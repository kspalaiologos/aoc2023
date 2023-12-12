module Main where

import Data.List.Split ( splitOn )
import Data.List ( intercalate )
import Data.Map ( Map, lookup, insert, empty )
import Control.Monad.Trans.State
    ( State, evalState, gets, modify' )
import Control.Arrow ((***))
import Control.Monad (join)

type Line = (String, [Int])
type Table = Map (Int, [Int]) Int

parse :: String -> [Line]
parse = map (\line -> let [c, g] = splitOn " " line in (c, map read (splitOn "," g))) . lines

withMemo :: (String -> [Int] -> State Table Int) -> String -> [Int] -> State Table Int
withMemo f s c = do
  memo <- gets (Data.Map.lookup (length s, c))
  case memo of
    Just res -> return res
    Nothing -> do
      res <- f s c
      modify' $ insert (length s, c) res
      return res

hashes :: String -> [Int] -> State Table Int
hashes [] [0] = return 1
hashes ('#':_) [] = return 0
hashes ('#':_) (0:_) = return 0
hashes [] _ = return 0
hashes ('?':xs) (0:cs) = consume xs cs
hashes ('?':xs) (c:cs) = withMemo hashes xs (c - 1:cs)
hashes s (0:xs) = consume s xs
hashes ('#':xs) (c:cs) = withMemo hashes xs (c - 1:cs)
hashes ('.':_) _ = return 0

consume :: String -> [Int] -> State Table Int
consume [] [] = return 1
consume [] _ = return 0
consume ('.':xs) c = consume xs c
consume ('#':xs) c = hashes ('#':xs) c
consume ('?':xs) c = (+) <$> consume ('#':xs) c <*> consume ('.':xs) c

solve :: Line -> Int
solve (s, c) = evalState (withMemo consume s c) empty

part1 :: [Line] -> Int
part1 = sum . map solve

part2 :: [Line] -> Int
part2 = sum . map (solve . ((intercalate "?" . replicate 5) *** (join . replicate 5)))

main :: IO ()
main = do
    input <- parse <$> readFile "input.txt"
    print $ part1 input
    print $ part2 input
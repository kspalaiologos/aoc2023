import Data.Char ( digitToInt )
import Data.List ( group, sortOn, partition, sort, sortBy)
import qualified Data.Ord
import Data.Ord (comparing)
import Control.Monad (liftM2, ap)

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

value :: Bool -> Char -> Int
value _ 'A' = 14
value _ 'K' = 13
value _ 'Q' = 12
value False 'J' = 11
value True 'J' = 0
value _ 'T' = 10
value _ c = digitToInt c

hist :: String -> [(Int, Char)]
hist = sortOn Data.Ord.Down . map (liftM2 (,) length head) . group . sortOn (value True)

classify :: Bool -> String -> [Int]
classify False hand = map fst (hist hand)
classify True "JJJJJ" = [5]
classify True hand = (fst n + sum (map fst jokers)) : map fst rest
  where (n : rest, jokers) = partition ((/= 'J') . snd) (hist hand)

parse :: String -> (String, Int)
parse input = (hand, read bid) where [hand, bid] = words input

solve :: Bool -> [(String, Int)] -> Int
solve = ((sum . zipWith ((`ap` snd) . (. fst) . const . (*)) [1..]) .) . sortOn . (. fst) . ap (ap . ((,) .) . classify) (map . value)

main :: IO ()
main = do
  input <- map parse <$> readLines "input.txt"
  print $ solve False input
  print $ solve True input

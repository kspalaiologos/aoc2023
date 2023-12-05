module Main where

import Data.Functor (($>), (<&>))
import Data.List (sort)
import Data.Maybe (mapMaybe)

type Range = (Int, Int)

data MapLine = MapLine Range Range deriving (Show)

type Map = [MapLine]

instance Eq MapLine where
  (==) (MapLine _ (s1, _)) (MapLine _ (s2, _)) = s1 == s2

instance Ord MapLine where
  compare (MapLine _ (s1, _)) (MapLine _ (s2, _))
    | s1 > s2 = GT
    | s1 < s2 = LT
    | otherwise = EQ

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

splitOn :: (Eq a) => a -> [a] -> [[a]]
splitOn d s = case dropWhile (== d) s of
  [] -> []
  s' -> w : splitOn d s''
    where (w, s'') = break (== d) s'

seeds :: [String] -> [Int]
seeds = map read . filter (/= "") . splitOn ' ' . last . splitOn ':' . head

maps :: [String] -> [Map]
maps = map (map ((\[dst, src, len] -> MapLine (dst, dst + len - 1) (src, src + len - 1)) . map read . splitOn ' ') <&> sort . tail) . splitOn "" . drop 2

applySeed :: Map -> Int -> Int
applySeed aMap src =
  let matches = filter (\(MapLine _ (s, e)) -> src >= s && src <= e) aMap
    in case matches of [MapLine (ds, de) (s, e)] -> ds + (src - s); [] -> src

locations :: [Int] -> [Map] -> [Int]
locations seeds maps = map (\seed -> foldr applySeed seed (reverse maps)) seeds

applyRange :: Map -> Range -> [Range]
applyRange [] r = [r]
applyRange ((MapLine (ds, de) (ms, me)) : rst) r@(s, e)
  | e < ms = [r]
  | s > me = applyRange rst r
  | s >= ms && e <= me = [(ds + (s - ms), de - (me - e))]
  | s < ms && e >= ms && s <= me = [(s, ms - 1), (ds, de - (me - e))]
  | s >= ms && s <= me && e > me = (ds + (s - ms), de) : applyRange rst (me + 1, e)
  | s < ms && e > me = (s, ms - 1) : (ds, de) : applyRange rst (me + 1, e)

locationRanges :: [Range] -> [Map] -> [Range]
locationRanges ranges maps = foldr (concatMap . applyRange) ranges $ reverse maps

asRanges :: [Int] -> [Range]
asRanges [] = []
asRanges (s : len : rst) = (s, s + len - 1) : asRanges rst

main :: IO ()
main = do
  seeds <- seeds <$> readLines "input.txt"
  maps <- maps <$> readLines "input.txt"
  print $ minimum $ locations seeds maps
  print $ minimum $ map fst $ locationRanges (asRanges seeds) maps
import Control.Monad.Trans.State
import Control.Monad (join)
import Data.Text (unpack)
import Data.List (transpose, elemIndices, sort, intercalate)
import Data.List.Split (splitOn)
import Data.Map (Map, singleton, insert, lookup)
import Prelude hiding (lookup)

type StateType = (Int, [String], Map [String] Int)

move :: [String] -> [String]
move = fmap (intercalate "#" . fmap sort . splitOn "#")

count :: [String] -> [[Int]]
count = fmap (fmap succ . elemIndices 'O')

rotate :: [String] -> [String]
rotate = fmap reverse . transpose

mcycle :: [String] -> [String]
mcycle = rmove . rmove . rmove . rmove
    where rmove = rotate . move

ncycles :: Int -> [String] -> [String]
ncycles = foldr (.) id . flip replicate mcycle

doCycles :: State StateType (Int, Int)
doCycles = do
  (n, p, m) <- get
  let p' = mcycle p
  case lookup p' m of
    Just v -> pure (v, n + 1)
    Nothing -> do put (n + 1, p', insert p' n m); doCycles

main :: IO ()
main = do
  input <- splitOn "\n" <$> readFile "input.txt"
  print $ sum . join . count . move . rotate $ input
  let p = rotate input
  let (s, r) = evalState doCycles (0, p, singleton p 0)
  let numRots = s + ((1000000000 - s) `mod` (r - s - 1))
  print $ sum . join . count $ ncycles numRots p
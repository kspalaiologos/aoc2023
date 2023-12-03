import Data.List (elemIndices, nub)
import Data.Char (isDigit)
import Text.Read (readMaybe)
import Data.Maybe (catMaybes)

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

positions :: [String] -> String -> [(Int, Int)]
positions grid options = map (\x -> (x `mod` rows, x `div` rows)) wi
  where wi = concatMap (\x -> elemIndices x (concat grid)) options
        rows = length grid

parseNum :: [String] -> (Int, Int) -> Maybe Int
parseNum grid (x, y) = if isDigit (row !! x) then readMaybe num else Nothing
  where row = grid !! y
        accept xs = take x xs ++ takeWhile isDigit (drop x xs)
        num = reverse $ takeWhile isDigit (reverse $ accept row)

numbersAround :: [String] -> (Int, Int) -> [Int]
numbersAround grid (x, y) = nub $ catMaybes radius
  where radius = [parseNum grid (x + dx, y + dy) | dx <- [-1, 0, 1], dy <- [-1, 0, 1]]

p1 :: [String] -> Int
p1 grid = sum $ concatMap (numbersAround grid) (positions grid "*@#-=/+%$&")

p2 :: [String] -> Int
p2 grid = sum $ map product (filter (\x -> 2 == length x) (map (numbersAround grid) (positions grid "*")))

main :: IO ()
main = do
  grid <- readLines "input.txt"
  print $ p1 grid
  print $ p2 grid
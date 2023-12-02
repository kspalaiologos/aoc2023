import Data.Char (isDigit, isAlpha)
import Data.List (groupBy, elemIndex, sortBy)
import Data.Maybe (fromJust, mapMaybe)
import Data.Function (on)

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

numbers :: String -> [Int]
numbers = map read . filter (all isDigit) . groupBy (\x y -> isDigit x == isDigit y)

alwords :: String -> [String]
alwords = filter (all isAlpha) . groupBy (\x y -> isAlpha x == isAlpha y)

colours :: String -> [String] -> [Int]
colours line options = mapMaybe (`elemIndex` options) (alwords line)

gameMax :: String -> [String] -> [Int]
gameMax g c = head x : map (maximum . map snd) (groupBy ((==) `on` fst) (sortBy (compare `on` fst) y))
  where x = numbers g; y = zip (colours g c) (tail x)

p1 :: String -> Maybe Int
p1 line = if and $ zipWith (<=) xs [12, 13, 14] then Just x else Nothing
  where x : xs = gameMax line ["red", "green", "blue"]

p2 :: String -> Int
p2 line = product (tail (gameMax line ["red", "green", "blue"]))

main :: IO ()
main = do
  lines <- readLines "input.txt"
  print $ sum $ mapMaybe p1 lines
  print $ sum $ map p2 lines
import Data.Maybe (mapMaybe, listToMaybe, fromMaybe, fromJust)
import Data.List (isPrefixOf, elemIndex)

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

-- Part 1
firstDigit :: String -> Char
firstDigit = head . filter (`elem` ['0'..'9'])

part1 :: [String] -> Int
part1 lines = sum (map (\x -> read [firstDigit x, firstDigit $ reverse x]) lines)

-- Part 2
firstNumber :: String -> [String] -> Int
firstNumber x d = fromMaybe (firstNumber (tail x) d) p
    where
        n = listToMaybe $ mapMaybe (\z -> if z `isPrefixOf` x then Just z else Nothing) d
        p = fmap (\x -> 1 + fromJust (x `elemIndex` d) `mod` 9) n

part2 :: [String] -> Int
part2 = sum . map (\line -> 10 * firstNumber line numbers + firstNumber (reverse line) (map reverse numbers))
    where numbers = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"] ++ [show x | x <- [1 .. 9]]

main = do
  lines <- readLines "input.txt"
  print $ part1 lines
  print $ part2 lines
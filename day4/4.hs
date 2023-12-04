import Data.Char (isDigit)

nums :: String -> [Int]
nums [] = []
nums xs = if null n then [] else read n : nums tl
  where
    hd = dropWhile (not . isDigit) xs
    n = takeWhile isDigit hd
    tl = dropWhile isDigit hd

readLines :: FilePath -> IO [String]
readLines file = do
  contents <- readFile file
  return $ lines contents

wins :: String -> Int
wins game = length (take 10 n `intersect` drop 10 n)
  where
    n = tail $ nums game
    intersect [] = const []
    intersect xs = filter (`elem` xs)

p1 :: [String] -> Int
p1 games = sum $ map (ep . wins) games
  where ep x = if x > 0 then 2 ^ (x - 1) else 0

p2 :: [String] -> [Int]
p2 [] = []
p2 (x : xs) = (1 + sum (take (wins x) r)) : r
  where r = p2 xs

main :: IO ()
main = do
  games <- readLines "input.txt"
  print $ p1 games
  print $ sum $ p2 games
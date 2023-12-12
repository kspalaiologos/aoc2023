import Data.Array (Array)
import Data.List (transpose)
import Data.Bifunctor ( Bifunctor(bimap) )

readData :: FilePath -> IO [[Bool]]
readData file = do
  contents <- readFile file
  return $ map (map (== '#')) (lines contents)

empty :: [[Bool]] -> ([Bool], [Bool])
empty grid = (map or grid, map or (transpose grid))

locations :: [[Bool]] -> [(Int, Int)]
locations grid = concat $ zipWith (\x y -> map (\z -> (x, z)) y) [0..] (map (map fst . filter snd . zip [0..]) grid)

cab :: (Int, Int) -> (Int, Int) -> Int
cab (x1, y1) (x2, y2) = abs (x1 - x2) + abs (y1 - y2)

scal :: [[Bool]] -> Int -> Int
scal grid factor = sum [cab (locs !! i) (locs !! j) | i <- [0..(length locs - 1)], j <- [0..i]]
    where (emptyRows, emptyCols) = empty grid
          rows = scan emptyRows
          cols = scan emptyCols
          locs = map (bimap (rows !!) (cols !!)) (locations grid)
          scan x = map pred (tail $ scanl (\acc x -> acc + if x then 1 else factor) 0 x)

main :: IO ()
main = do
  grid <- readData "input.txt"
  putStrLn $ "Part 1: " ++ show (scal grid 2)
  putStrLn $ "Part 2: " ++ show (scal grid 1000000)
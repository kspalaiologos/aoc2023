import qualified Data.Map as Map

type Grid = Map.Map String (String, String)

insertLine :: Grid -> String -> Grid
insertLine grid line = Map.insert (take 3 line) (take 3 (drop 7 line), take 3 (drop 12 line)) grid

parse :: String -> (String, Grid)
parse input = (head (lines input), foldl insertLine Map.empty (tail $ tail (lines input)))

p1 :: Grid -> String -> String -> Int
p1 grid "ZZZ" path = 0
p1 grid current (p : ps) = 1 + p1 grid newElem ps
    where newElem = if p == 'L' then fst (grid Map.! current) else snd (grid Map.! current)

main :: IO ()
main = do
    input <- readFile "input.txt"
    let (start, grid) = parse input
    print $ p1 grid "AAA" (cycle start)
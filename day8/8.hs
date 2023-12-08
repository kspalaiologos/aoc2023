import qualified Data.Map as Map

type Grid = Map.Map String (String, String)

insertLine :: Grid -> String -> Grid
insertLine grid line = Map.insert (take 3 line) (take 3 (drop 7 line), take 3 (drop 12 line)) grid

parse :: String -> (String, Grid)
parse input = (head (lines input), foldl insertLine Map.empty (tail $ tail (lines input)))

steps :: Grid -> String -> String -> Int
steps grid (_ : _ : "Z") path = 0
steps grid current (p : ps) = 1 + steps grid newElem ps
    where newElem = if p == 'L' then fst (grid Map.! current) else snd (grid Map.! current)

-- A shitty implementation.
factors :: Int -> [Int]
factors n = [x | x <- [2..n-1], n `mod` x == 0]

main :: IO ()
main = do
    input <- readFile "input.txt"
    let (start, grid) = parse input
    print $ steps grid "AAA" (cycle start)
    let keys = filter (\x -> 'A' == last x) (Map.keys grid)
    let f = map (factors . (\x -> steps grid x (cycle start))) keys
    print $ product (map head f) * last (head f)


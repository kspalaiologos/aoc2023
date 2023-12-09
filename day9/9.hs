
binom :: Int -> [Int]
binom n = z (map (n `f`) [0..n-1]) where
    f n 0 = 1; f 0 k = 0
    f n k = f (n-1) (k-1) * n `div` k
    z (a : b : xs) = a : -b : z xs
    z (a : xs) = a : z xs
    z [] = []

dot :: [Int] -> [Int] -> Int
dot a b = sum $ zipWith (*) a b

main :: IO ()
main = do
    lines <- lines <$> readFile "input.txt"
    let numbers = (fmap read <$> map words lines) :: [[Int]]
    let binomials = map (binom . length) numbers
    print $ sum $ zipWith dot binomials numbers
    print $ sum $ zipWith dot binomials (map reverse numbers)

f :: Double -> Double -> Integer
f a w = z
  where
    v = sqrt(a * a - 4 * w)
    x = floor(0.5 * (a + v))
    y = floor(0.5 * (a - v))
    z = x - y

main :: IO ()
main = do
  let t = [53.0,89.0,76.0,98.0]
  let d = [313.0,1090.0,1214.0,1201.0]
  print $ product $ zipWith f t d
  print $ f 53897698.0 313109012141201.0
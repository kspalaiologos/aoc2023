import Control.Applicative
import Data.List ( transpose, find )
import Data.List.Split ( splitOn )
import Data.Maybe ( fromJust )
import Control.Monad ( liftM2 )

distance :: Int -> [String] -> Int
distance n = sum . map (valid . splitAt n)
 where valid = uncurry (((length . filter not) .) . zipWith (==) . reverse)

score :: Int -> [String] -> Maybe Int
score diff = liftM2 (<|>) index (((100 *) <$>) . index . transpose)
 where index g = find ((diff ==) . flip distance g) [1 .. length (head g) - 1]

solve :: Int -> [[String]] -> Int
solve = (sum .) . map . (fromJust .) . score

main :: IO ()
main = do
  grid <- map lines . splitOn "\n\n" <$> readFile "input.txt"
  print $ solve 0 grid
  print $ solve 1 grid
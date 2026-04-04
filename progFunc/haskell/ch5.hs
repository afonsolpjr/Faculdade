import Data.Char 
factors :: Integral a => a -> [a]
factors n = [x | x <- [1..n], n `mod` x == 0]

prime :: Integral a => a -> Bool
prime n = factors n == [1,n]


primes :: Integral a => a -> [a]
primes n = [x | x <- [2..n], prime x]



adj :: [a] -> [(a,a)]
adj xs = zip xs (tail xs)


sorted :: Ord a => [a] -> Bool
sorted xs = and [x <= y | (x,y) <- adj xs]

-- Using zip we can also define a function that returns the list of all positions at which a value occurs in a list

pos :: Eq a => a -> [a] -> [Int]
pos x xs = [y | (x',y) <- zipped, x' == x ]
  where zipped = zip xs [0..(length xs - 1)]


-- Caesar Cipher

caesarEncodeChar :: Int -> Char -> Char
caesarEncodeChar n c 
  | ord c + n > ord 'z' = chr (ord 'a' + (ord c + n - 1) `mod` ord 'z')
  | c == ' '            = ' '
  | otherwise           = chr (ord c + n)

caesarEncode :: String -> Int -> String
caesarEncode s n = map (caesarEncodeChar n) s
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

let2int :: Char -> Int
let2int c = (ord c) - ord 'a'

int2let :: Int -> Char
int2let n = chr (ord 'a' + n)

caesarEncodeChar :: Int -> Char -> Char
caesarEncodeChar n c 
  | c == ' '            = ' '
  | otherwise           = int2let ((let2int c + n) `mod` 26)

caesarEncode :: String -> Int -> String
caesarEncode s n = map (caesarEncodeChar n) s

caesarDecode :: String -> Int -> String
caesarDecode s n = caesarEncode s (-n)

-- counting lowers

lowers :: [Char] -> Int
lowers xs = length [ x | x <- xs, x >='a' && x <='z' ]

count :: Eq a => a -> [a] -> Int
count needle haystack = length [x | x <- haystack, x == needle]

-- freq tables of lower chars

percent :: Int -> Int -> Float
percent n m = (fromIntegral n / fromIntegral m) * 100


-- freqs :: [Char] -> [Float]
freqs str = [ percent (count c str) (lowers str) | c <- ['a'..'z'] ]
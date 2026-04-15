import Data.Char 
factors :: Integral a => a -> [a]
factors n = [x | x <- [1..n], n `mod` x == 0]

prime :: Integral a => a -> Bool
prime n = factors n == [1,n]


primes :: Integral a => a -> [a]
primes n = [x | x <- [2..n], prime x]


findkv :: Eq a => a -> [(a,b)] -> [b]
findkv key list = [value | (actualKey,value) <- list, key == actualKey ]


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

chisqr :: [Float] -> [Float] -> Float
chisqr ofs efs = sum [ (o - e)^2 / e | (o,e) <- zip ofs efs ]

rotate :: [a] -> Int -> [a]
rotate xs n = drop n xs ++ take n xs

-- Exercícios:

-- Ex 1
sumsqrs = sum [ x^2 | x <- [1..100] ]

-- Ex 2

grid :: Int -> Int -> [(Int,Int)]
-- todas combinacoes de As e Bs em pares: [ (a,b) | a <- A, b <- B ]
grid m n = [ (x,y) | x <- [0..m], y <- [0..n]]

-- Ex 3

squareGrid :: Int -> [(Int,Int)]
squareGrid n = [ (x,y) | (x,y) <- grid n n, x /= y]

-- Ex 4

myReplicate :: Int -> a -> [a]
myReplicate n x = [x | _ <- [1..n]]

-- Ex 5

pythagoreans :: Int -> [(Int,Int,Int)]

-- todos quadrados de 1 a n
pythagoreans n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [y..n],
  x^2 + y^2 == z^2]

-- Ex 6

perfects :: Int -> [Int]
perfects n = [x | x <- [1..n], x == sum (init (factors x))]

-- Ex 7 

l1 = [ (x,y) | x <- [1,2], y <- [3,4]]
l2 = concat [ [(x,y) | y <- [3,4]] | x <- [1,2] ]

-- Ex 8 

-- queremos pegar uma funcao que retorna em uma key:value list todos os valores de uma chave, e usar pra retornar a posicao de um elemento no array.
-- como  a posicao do elemento em um array pode ser representada deste modo?

positions_kv :: Eq a => a -> [a] -> [Int] 

positions_kv needle haystack = findkv needle zipped_haystack
  where zipped_haystack = zip haystack [0..(length haystack)-1]

scalarproduct :: [Int] -> [Int] -> Int
-- he wants it in a similar way to the definition of chisqr on the book
scalarproduct v1 v2= sum [ a*b | (a,b) <- zip v1 v2]


-- Exercicio 10 vai ficar pra depois k
-- Ele usa essa tabela de frequencias aqui 
-- table = [8.1, 1.5, 2.8, 4.2, 12.7, 2.2, 2.0, 6.1, 7.0,
-- 0.2, 0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0,
-- 6.3, 9.0, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1]


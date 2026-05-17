import Data.Char
import Data.List 
--Maps
map' :: ( a -> b ) -> [a] -> [b]
map' f xs = [ f x | x <- xs  ]

--Defining map recursively

mapr f []     = []
mapr f (x:xs) = ((f x):(mapr f xs))
 
 
filter' :: ( a -> Bool ) -> [a] -> [a]
 
filter' f xs = [ x | x <- xs, f x ]

-- 

filterr :: ( a -> Bool) -> [a] -> [a]
 
filterr f [] = []
filterr f (x:xs)
  | f x         = x : filterr f xs
  | otherwise   = filterr f xs

-- Definição de foldr na biblioteca padrão:
--   foldr :: Foldable t => (a -> b -> b) -> b -> t a -> b
-- Isto é: 
-- Como esta definição é geralmente utilizado na prática, para definir outras?
-- Simples, nós só precisamos passamos alguns de seus parametros, e não todos.
-- A função é de 3 parâmetros:
--  1. uma operação para elementos da lista
--  2. um caso base para quando a lista é vazia
--  3. uma lista
-- Ao passar só dois parâmetros, o retorno será uma função do tipo:
-- Foldable t => t a -> b
--

flen :: [a] -> Int
flen    = foldr (\_ -> (+1)) 0

--rev' :: [a] -> [a]
--rev' []       = []
--rev' (x:xs)   = rev' (x:xs)


-- Perdi muito tempo tentando entender porque xs:x não funcionava
-- e porque eu tinha que fazer xs ++ [x].
-- A explicação está na definição da cons.
-- (:) :: a -> [a] -> [a]

rev :: [a] -> [a]
rev     = foldr ( \x xs -> xs++[x] ) []


-- foldL !!!!!!!!!!!!!!!!!!!!
-- Parece codigo imperativo imperativo, mas não.. 
-- Nesta implementacao de 'sum', usamos um acumulador.

-- foldl :: Foldable t => ( b -> a -> b) -> b -> t a -> b
sumacc :: Num a => [a] -> a
sumacc  = acc 0 -- sou um acumulador e quero uma lista, começando com 0
  where
    acc n []        = n -- nao tendo mais ng, eu paro
    acc n (x:xs)    = acc (n+x) xs -- pego o da frente e continuo


-- E agora.... veja com foldl
sumac :: Num a => [a] -> a

sumac = foldl (+) 0 -- ( ˶°ㅁ°)!! 

-- Vou tentar cobrir os casos que vimos no foldr

revl :: [a] -> [a]
revl    = foldl (\acc elem -> elem:acc ) []

-- fllen fold left length
-- first lets define the accumulator version

lenacc :: [a] -> Int
lenacc  = acc 0
  where
    acc v []        = v
    acc v (x:xs)    = acc (v+1) xs

 
fllen :: [a] -> Int
fllen = foldl (\acc _-> (acc+1)) 0



--- Binary String Transmitter

type Bit = Int

bin2int' :: [Bit] -> Int
-- We assume a binary number is inverted. 
-- 10, which is represented by 1010, would be [0,1,0,1]

bin2int' bits    = sum [ weight * bit | (weight,bit) <- zip weights bits]
                  where
                    weights = iterate (*2) 1
-- using foldr

bin2int :: [Bit] -> Int
-- always recall foldr :: (a -> b -> b) -> b -> [a] -> b
bin2int     = foldr (\x y -> x + (2*y) ) 0

int2bin :: Int -> [Bit]
int2bin 0  = []
int2bin x  = x `mod` 2 : (int2bin (x `div` 2))

pad8 :: [Bit] -> [Bit]
pad8 b  = take 8 ( b ++ repeat 0 )

-- the encode function takes a string and serializes the string,
-- first transforming each character in a byte, then merging them
-- together in a binarry stream

encode :: String -> [Bit]
-- thats sick
-- encode str = concat (map pad8 (map int2bin (map ord str )))

encode =  concat .map (pad8 . int2bin . ord) 



--- Decoding. First group in 'bytes'
chop8 :: [Bit] -> [[Bit]]
chop8 []    = []
chop8 x     = take 8 x : chop8 (drop 8 x)

-- to decode, first byte
-- then transform on a int
-- then convert to char

-- foldr :: (a -> b -> b) -> b -> [a] -> b
-- our case:
-- a = Bit/Int
-- b = String

decode :: [Bit] -> String
decode  =  map  (chr . bin2int) . chop8 



---------- Voting algorithm

count :: Ord a => a -> [a] -> Int
count x = length . filter (x==)

rmDups :: Ord a => [a] -> [a]
rmDups (x:xs)   =  x : filter (/= x) xs

result :: Ord a => [a] -> [(Int,a)]
result votes    = sort [(count cand votes, cand) | cand <- (rmDups votes)]

votes = ["Red", "Blue", "Green", "Blue", "Blue", "Red"]

winner :: Ord a => [a] -> a
winner  = snd . last . result 

-- alternative
rmEmpty :: Eq a => [[a]] -> [[a]]
rmEmpty     = filter (/= [])

eliminate :: Eq a => a -> [[a]] -> [[a]]
eliminate cand  = filter (not . elem cand)

-- get candidate with least votes
-- ranking
rank :: Ord a => [[a]] -> [a]
rank = map snd . result . map head 

winner' :: Ord a => [[a]] -> a
winner' votes = case rank (rmEmpty votes) of
  [cand]       -> cand
  (cand:cs)    -> winner' (eliminate cand votes)



-- Exercicios

-- 1 
mapfilter :: (b -> a) -> (b -> Bool) -> [b] -> [a]
mapfilter f p  = map f . filter p

-- 2
all' :: (a -> Bool) -> [a] -> Bool
all' p = foldr  ( (&&) . p ) True

any' :: (a -> Bool) -> [a] -> Bool
any' p = foldr ( (||) . p ) False


takeuaile :: ( a -> Bool ) -> [a] -> [a]
takeuaile p []      = []
takeuaile p (x:xs) 
  | p x         = x : takeuaile p xs
  | otherwise   = []


tuai :: ( a -> Bool ) -> [a] -> [a]
tuai p = foldr (\x xs -> if p x then (++) [x] xs else [] ) []


-- recursive first
dropuai' :: ( a -> Bool) -> [a] -> [a]
dropuai' p [] = []
dropuai' p (x:xs)
  | p x         = dropuai' p xs
  | otherwise   = x:xs

-- foldr :: (a -> b -> b) -> b -> [a] -> b
-- foldl :: (b -> a -> b) -> b -> [a] -> b
-- foldr f v x:xs = f x (foldr f v xs)
-- foldl f v x:xs = foldl f (f v x) xs


dropuai :: ( a -> Bool) -> [a] -> [a]
dropuai p = foldl (\xs x -> if p x && null xs then [] else xs ++ [x]  ) [] 


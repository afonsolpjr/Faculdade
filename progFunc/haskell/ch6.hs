fac :: Int -> Int
fac x = product [1..x]


facr :: (Eq a, Num a) => a -> a
facr 0 = 1
facr x = x * facr (x -1)

product' :: Num a => [a] -> a
product' []     = 1
product' (x:xs) = x * product' xs

length' :: Integral b => [a] -> b 
length' []      = 0
length' (_:xs)  = 1 + length' xs

reverse' :: [a] -> [a]
reverse' []     = []
reverse' (x:xs) = (reverse' xs) ++ [x]

sortedInsert :: Ord a => a -> [a] -> [a]
-- recursively?
sortedInsert a []       = [a]
sortedInsert a (x:xs)   
    |   a <= x      = (a:x:xs)
    |   otherwise   = (x: sortedInsert a xs)

insertionSort :: Ord x => [x] -> [x]
insertionSort []        = []
insertionSort (x:xs)    = sortedInsert x (insertionSort xs)

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _           = []
zip' _ []           = []
zip' (a:as) (b:bs)  = (a,b) : zip' as bs

take' :: Integral i => i -> [a] -> [a]
take' i []      = []
take' 0 (x:xs)  = []
take' i (x:xs)  = x : take' (i-1) xs


drop' :: Integral i => i -> [a] -> [a]
drop' i []      = []
drop' 0 (x:xs)  = (x:xs)
drop' i (x:xs)  = drop' (i-1) xs


fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-2) + fib(n-1)

suml2 :: [Int] -> Int
suml2 (x:y:[]) = x + y
suml2 (x:y:z)  = suml2 (y:z)


fibs :: Int -> [Int]
fibs 0 = []
fibs 1 = [0]
fibs 2 = [0,1]
fibs n = fib_list ++ [suml2 fib_list]
	where fib_list = fibs (n-1)

init' :: [a] -> [a]

init' []         = []
init' (x:xs)     = x : init xs

-- Exercicios

-- 1
facr' :: (Ord a, Num a) => a -> a
facr' x   | x < 0       = -1
          | x == 0      = 1
          | otherwise   = x  * (facr' (x-1))

-- 2

sumdown :: Int -> Int
sumdown 0 	= 0
sumdown x 	= x + sumdown (x-1) 

-- 3
pow :: Int -> Int -> Int
pow _ 0	        = 1
pow 0 _	        = 0
pow x y         = x * (pow x (y-1)) 
{-
 - How 2^3 works:
 - pow 2 3 ->
 - 2 * (pow 2 2) ->
 - 2 * (2 * (pow 2 1))
 - 2 * (2 * (2 * (pow 2 0)))
 - 2 * (2 * (2 * 1))
 - 2 * (2 * 2)
 - 2 * 4
 - 8
-}


-- Exercicio 4
-- 6 27
-- 6 21
-- 6 15
-- 6 9
-- 6 3
-- 3 3

-- 20 8
-- 12 8
-- 4 8
-- 4 4

euclid :: Int -> Int -> Int

euclid x 0 = x
euclid 0 x = x
euclid 1 _ = 1
euclid _ 1 = 1
euclid x y 
    | x < y     = euclid x (y-x)
    | x == y    = x
    | x > y     = euclid y (x-y)

-- Exercicio 5
--
-- length [1,2,3] ->
-- 1 + length [2,3] ->
-- 1 + 1 + length [3] ->
-- 1 + 1 + 1 + length [] ->
-- 1 + 1 + 1 + 0
-- 
-- drop 3 [1,2,3,4,5] ->
-- drop 2 [2,3,4,5] ->
-- drop 1 [3,4,5] ->
-- drop 0 [4,5] ->
-- [4,5]
--
-- init [1,2,3]
-- 1 : init [2,3]
-- 1 : 2 : init [3]
-- 1 : 2 : 3 : init []
-- 1 : 2 : 3 : []
--
--

-- Exercicio 6
--

and' :: [Bool] -> Bool
and' []         = True
and' (x:xs) 
    | x         = and' xs
    | otherwise = False

concat' :: [[a]] -> [a]
concat' []      = []
concat' (x:xs)  = x ++ concat' xs

replicate' :: Int -> a -> [a]
replicate' 0 _  = []
replicate' x y  = y : replicate' (x-1) y

select :: [a] -> Int -> a
select (x:xs) 0         = x
select (x:xs) i         = select xs (i-1)

elem' :: Eq a => a -> [a] -> Bool
elem' _ []          = False
elem' x (cand:xs)
    |   x == cand       = True
    |   otherwise       = elem' x xs

-- Exercicio 7

merge :: Ord a => [a] -> [a] -> [a]
merge [] []     = []
merge x []      = x
merge [] y      = y
merge (x:xs) (y:ys)
    | x < y     = x : merge xs (y:ys)
    | x >= y    = y : merge (x:xs) ys

-- merge [2,5,6] [1,3,4]
-- merge [1,2] (merge [5,6] [3,4])
-- merge [1,2] (merge [3,5] (merge [6] [4]))
-- merge [1,2] (merge [3,5] [4,6])
-- merge [1,2] (merge [3,4] (merge [5] [6]))
-- merge [1,2] (merge [3,4] [5,6])
   
msort :: Ord a => [a] -> [a]
msort []        = []
msort [x]       = [x]
msort x
    | even (length x)   = merge (msort (half1 x)) (msort (half2 x))
    | otherwise         = merge (msort (half1 x)) (msort (oddhalf x))
        where
            half        = div (length x) 2
            half1       = take half
            half2       = drop half
            oddhalf     = drop (half+1)

-- Exercicio 8

-- a
sum' :: Num a => [a] ->a
sum' []         = 0
sum' (x:xs)     = x + sum' xs

-- b
mytake :: Int -> [a] -> [a] --hahahah
mytake 0 _      = []
mytake _ []     = []
mytake n (x:xs) = x : mytake (n-1) xs

-- c

mylast :: [a] -> a
mylast []	= 0
mylast [x] 	= x
mylast (_:xs)	= mylast xs

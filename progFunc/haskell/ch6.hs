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



{-
Exercicios 27/04 
fazer uma lista infinita parecida com
primes = filterprimes [2..]
a partir de uma lista de numeros candidatos, queremos obter apenas os numeros primos.
caso o primeiro numero seja primo podemos retiirar os seus multiplos do 'restante' da lista.



exercicio 2 :
hamming number
todos numeros cujos unicos fatores primos sao 2,3,5.
podemos defini-los assim
1 é HN
se x é HN, 2x,3x,5x são HN

objetivo: construir uma lista infinitia desses numeros em ordem crescente 
-}
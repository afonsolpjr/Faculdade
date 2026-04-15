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
drop' 0 (x:xs)  = xs
drop' i (x:xs)  = drop' (i-1) xs
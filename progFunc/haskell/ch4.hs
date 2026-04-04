-- Exercicio 4.1
halve :: [a] -> ([a],[a])
halve x = (take half x, drop half x )
  where half = length x `div` 2

-- Exercicio 4.2

-- Define a function third :: [a] -> a that returns the third element in a list that contains at least this many elements using:
third :: [a] -> a

-- a. head and tail;
third x = head (tail (tail x))
-- b. list indexing !!;
third1 :: [a] -> a
third1 x = x !! 2
-- c. pattern matching.
third2 :: [a] -> a
third2 (_:(_:(z:_))) = z

-- Consider a function safetail :: [a] -> [a] that behaves in the same way as tail 
-- except that it maps the empty list to itself rather than producing an error.
-- Using tail and the function null ::
-- [a] -> Bool that decides if a list is empty or not, define safetail using:

-- a. conditional expression;
safetail1 :: [a] -> [a]
safetail1 x = 
  if null x then []
  else tail x

-- b. guarded equations;
safetail2 :: [a] -> [a]
safetail2 x | null x    = []
            | otherwise = tail x

-- c. pattern matching
safetail3 :: [a] -> [a]
safetail3 [] = []
safetail3 x = tail x

-- Exercicio 5

x && y = if x then
    if y then True
      else False
    else False
  
-- Exercicio 6

x && y = if x then y
  else False


-- Exercicio 7
-- Show how the meaning of the following curried function definition can be formalised in terms of
-- lambda expressions:
-- mult :: Int -> Int -> Int -> Int
-- mult x y z = x*y*z

-- mult :: Int -> Int -> Int -> Int
mult = \x -> (\y -> (\z -> (x * y * z)))


-- Exercicio 8

luhnDouble :: Int -> Int
luhnDouble x  
  | x * 2 >= 10   = x*2 - 9
  | otherwise     = x*2

luhn :: Int -> Int -> Int -> Int -> Bool
luhn a b c d = (a2 + b + c2 + d) `mod` 10 == 0
  where
    a2 = luhnDouble a
    c2 = luhnDouble c
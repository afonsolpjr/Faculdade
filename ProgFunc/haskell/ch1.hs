{- Exercicio 3 -}

product' [] = 1
product' (x:xs) = x * product' xs

{- Exercicio 4

Definição normal:
qsort []        = []
qsort (x:xs)    = qsort smaller ++ [x] ++ qsort larger
    where
        smaller = [a | a <- xs, a <= x]
        larger = [b | b <- xs, b > x]
-}


qsort' []        = []
qsort' (x:xs)    = qsort' larger ++ [x] ++ qsort' smaller
    where
        larger  = [a | a <- xs, a >= x]
        smaller = [b | b <- xs, b < x]

{- Exercício 5
Tirando a condição de igualdade,
retiraríamos as repetições do resultado. -}
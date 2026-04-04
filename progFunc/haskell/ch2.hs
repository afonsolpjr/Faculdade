{-

Exercicio 2.

        (2^3)*4
        (2*3)+(4*5)
        2+(3*(4^5))

Exercicio 3.
    3.1 begin with lowercase
    3.2 wrong identation 
    3.3 what was the 3rd error?
-}

n = a `div` length xs
    where
        a = 10
        xs = [1,2,3,4,5]


-- Exercício 4

last1 x = head (reverse x )

last2 x = x !! (length x - 1)

-- Exercício 5

init1 x = take (length x - 1) x

init2 [x]       = []
init2 (x:xs)    = [x] ++ init2 xs
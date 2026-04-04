{- 

Int vs Integer

Int é o signed int em 64 bits. Um typecast 
do tipo "2^63 :: Int" retorna um número negativo,
enquanto "2^64 :: Integer", não.

-}

{-
Listas:
Ou são vazias, ou são de um tipo só.

1. Uma lista não guarda informações associada a seu tamanho.
2. Podemos ter listas dos mais variados tipos.
3. Listas podem ser infinitas.


Tuplas:

Sequência de componentes que podem ter tipos diferentes.

1. Como tipos são basicamente coleções de valores,
uma tupla (Int,Bool) são todas as sequências possíveis de 
inteiros seguidos de um Bool... 
(qual a utilidade prática dessa definição?)

2. Tuplas podem ter componentes dos mais variados tipos.
3. Tuplas precisam ter um número finito de componentes,
pois os tipos precisam ser inferidos antes da avaliação delas.




Sobre Classes:

Tipos = coleções de valores relacionados

Classes = Coleção de tipo relacionados (geralmente coleção de tipos que aceitam um determinado método overloaded com a classe)

Exercicios:


1.

[char]
(char,char,char)
[(Bool,char)]
([Bool],[Char])

[[a] -> [a]] Uma lista de funções que levam [a] em [a]

2.

bools = [False,True]

nums = [[1,3,5],[2,4,6]]

add :: Int -> Int -> Int -> Int

add a b c = a+b-c

Essa é dificil:
apply :: (a -> b) -> a -> b

discussao: https://stackoverflow.com/questions/37470354/function-with-type-a-b-in-haskell

-}

apply :: (a -> b) -> a -> b
apply func args = func args 

{-

Exercicio 3:

3.1 second xs = head (tail xs)

xs é uma lista
second xs :: [a] -> a

3.2 swap (x,y) = (y,x)

swap :: (a,b) -> (b,a) 

3.3
pair :: a -> b -> (a,b)

3.4
double :: Num a => a -> a

3.5
palindrome: Eq a => [a] -> bool

3.6
twice :: (a -> a) -> a -> a

4. Funções não podem ser instâncias de Eq...  pois são funções? Elas transformam valores, e realmente só faz sentido dizer que duas funções são iguais se elas sempre mapeam os mesmos argumentos para os mesmos resultados. Mas daí pra pensar numa forma de fazer elas serem instâncias de Eq é muito díficil. Os pares de inputs -> saidas podem ser diversos.
-}
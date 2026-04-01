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

-}


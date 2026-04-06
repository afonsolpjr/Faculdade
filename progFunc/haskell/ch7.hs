-- Maps
map' :: ( a -> b ) -> [a] -> [b]
map' f xs = [ f x | x <- xs  ]

-- Defining map recursively

mapr f []     = []
mapr f (x:xs) = ((f x):(mapr f xs))
 
 
filter' :: ( a -> Bool ) -> [a] -> [a]
 
filter' f xs = [ x | x <- xs, f x ]
 
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

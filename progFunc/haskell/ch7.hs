-- Maps
map' :: ( a -> b ) -> [a] -> [b]
map' f xs = [ f x | x <- xs  ]

-- Defining map recursively

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







{-
prove as equacoes abaixo:
-- ex 1
map f . map g    = map (f . g)
-- ex 2
map f (xs ++ ys) = map xs ++ map ys


-- definicoes pertinentes
map :: (a -> b) -> [a] -> [b]

map f []        = []
map f (x:xs)    = (f x):(map f xs)

(.) :: (b -> c) -> (a -> b) -> (a -> c)
(.) f g x = f (g x)   




--expandindo o lado esquerdo
-- podemos meter um xs como argumento na prova porque provar que duas funcoes são iguais é a mesma coisa que provar que para qualquer argumento elas terão o mesmo resultado, neah

map f (map g xs) = map (f . g) xs

-- usando o caso base da inducao: xs = []

map f (map g []) = map (f .g) []
map f ([]) = []
[] = []

-- provando o  (x:xs) assumindo que vale para xs
-- map f . map g    = map (f . g)
-- map f . map g xs = map (f . g) xs
map f (map g (x:xs))        = map (f .g) (x:xs)
map f ((g x):(map g xs))    = (f . g) x:(map (f.g) xs)
-- expandino lado esquerdo
f (g x):(map f (map g xs))      = (f . g) x:(map (f.g) xs)
(f . g) x:(map f (map g xs))    = (f . g) x:(map (f.g) xs)
(f . g) x:(map f . map g xs)    = (f . g) x:(map (f.g) xs)



-- exercicio 2
map f (xs ++ ys) = map f xs ++ map f ys

-- definicao pertinente
(++) :: [a] -> [a] -> [a]
[] ++ ys     = x
(x:xs) ++ ys = x:(xs ++ ys)

-- dando um spoiler: só fazer uma inducao em xs. porque basta fazer uma inducao em xs, nesse caso? porque sim

-- inducao em xs. caso base:
map f ([] ++ ys) = map f [] ++ map f ys
map f ys = [] ++ map f ys = map f ys

-- inducao em xs = (x:xs), sendo que ja vale para xs


map f ((x:xs) ++ ys) = map f (x:xs) ++ map f ys
--expandindo o ++ no lado esquerdo 

map f (x:(xs ++ ys)) = map f (x:xs) ++ map f ys
-- expandindo map do lado esquerdo
f x:(map f (xs ++ ys))  = map f (x:xs) ++ map f ys
-- expandindo o primeiro map do lado direito
f x:(map f (xs ++ ys))  = f x:(map f xs) ++ map f ys
-- expandindo o ++ do lado direito
f x:(map f (xs ++ ys))  = f x:(map f xs ++ map f ys)

-- e pela hipotese de inducao, temos a prova!


-- exercicio 3
data Tree n = Leaf n | Node (Tree n) (Tree n)

dada a definicao:
flatten :: Tree n -> [n]
flatten (Leaf n)    = [n]
flatten (Node l r)  = flatten l ++ flatten r

crie a função flatten', mais eficiente, a partir da igualdade:

flatten' t xs = flatten t ++ xs

-- inducao em t. caso folha

flatten' (leaf n) xs = flatten (leaf n) ++ xs
--expandindo lado direito
flatten' (leaf n) xs = [n] ++ xs = n:xs

-- caso t = (Node l r) onde a propriedade já vale para l e r 
-- ou seja: flatten' r xs = flatten r ++ xs
-- e:       flatten' l xs = flatten l ++ xs

-- Queremos provar a equação abaixo, dado a hipotese de indução acima.
flatten' (Node l r) xs = flatten (Node l r) ++ xs
-- expandindo lado direito (def de flatten)
flatten' (Node l r) xs = (flatten l ++ flatten r) ++ xs
-- associatividade a direita no lado direito
flatten' (Node l r) xs = flatten l ++ (flatten r ++ xs)
-- pela hipotese de inducao, temos no lado direito que:
flatten' (Node l r) xs = flatten l ++ (flatten' r xs)
-- e pela hipotese de inducao, novamente
flatten' (Node l r) xs = flatten' l (flatten' r xs)



-}



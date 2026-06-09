data Nat = Zero | Succ Nat
  deriving Show

add :: Nat -> Nat -> Nat
add Zero      n = n
add (Succ m)  n = Succ (add m n)


data Shape = Circle Float | Rect Float Float
  deriving (Eq,Ord)



-- Tautology Checker

-- Associations
type Assoc a b  = [(a,b)]


-- function that returns the first value that is associated with a given key in a table 
find :: Eq k => k -> Assoc k v -> v
find k x  = head [values | (key,values) <- x, key == k]

-- A substitution list is an association of a Char with an Bool
type Subst = Assoc Char Bool

-- Propositions
data Prop = Const Bool
  | Var Char
  | Not Prop
  | And Prop Prop
  | Imply Prop Prop

-- Substituting propositions

eval :: Subst -> Prop -> Bool
eval _ (Const b)      = b
eval s (Var p)        = find p s
eval s (Not p)        = not (eval s p)
eval s (And p1 p2)    = eval s p1 && eval s p2
eval s (Imply p1 p2)  = eval s p1 <= eval s p2

getVars :: Prop -> [Char]
getVars (Const b)     = []
getVars (Var p)       = [p]
getVars (Not p)       = getVars p
getVars (And p1 p2)   = getVars p1 ++ getVars p2
getVars (Imply p1 p2) = getVars p1 ++ getVars p2

-- From ch7

type Bit = Int
int2bin :: Int -> [Bit]
int2bin 0  = []
int2bin x  = x `mod` 2 : int2bin (x `div` 2)


rmDups :: Ord a => [a] -> [a]
rmDups []       = []
rmDups (x:xs)   =  x : rmDups (filter (/= x) xs)
-----------------------------------------------------
bools :: Int -> [[Bool]]
bools 0 = []
bools 1 = [[False],[True]]
bools n = (append False previous) ++ (append True previous)
  where
    previous = bools (n-1)
    append b = map (\xs -> [b] ++ xs)

--
substitutions :: Prop -> [Subst]
substitutions p = map (zip vars) (bools (length vars))
  where vars = rmDups (getVars p)

p1 :: Prop
p1 = And (Var 'A') (Not (Var 'A'))
p2 :: Prop
p2 = Imply (And (Var 'A') (Var 'B')) (Var 'A')
p3 :: Prop
p3 = Imply (Var 'A') (And (Var 'A') (Var 'B'))
p4 :: Prop
p4 = Imply (And (Var 'A') (Imply (Var 'A') (Var 'B'))) (Var 'B')

isTaut :: Prop -> Bool
isTaut (Const b)  = b
isTaut p          = not (any (==False) evals)
  where
    evals = [ eval s p | s <- substitutions p]



-- Exercise 1 

-- Copying definitions:

int2nat :: Int -> Nat
int2nat 0 = Zero
int2nat n = Succ (int2nat (n-1))

nat2int :: Nat -> Int
nat2int Zero      = 0
nat2int (Succ m)  = nat2int m + 1

-- add :: Nat -> Nat -> Nat
-- add Zero      n = n
-- add (Succ m)  n = Succ (add m n)

mult :: Nat -> Nat -> Nat
mult  Zero        _ = Zero
mult  (Succ Zero) n = n
mult  (Succ m)    n = add n (mult m n)


-- Exercise 2 

data Tree a = Leaf a | Node (Tree a) a (Tree a)


occurs :: Ord a => a -> Tree a -> Bool
occurs x (Leaf n)     = n == x 
occurs x (Node l v r) = case compare x v of
  LT  -> occurs x l 
  EQ  -> True
  GT  -> occurs x r
-- Seems like compare only does one operation, compared to 3 in the guard version of the function 
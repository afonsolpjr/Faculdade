  1 loop :: [a] -> [a] -> [a]
  2 
  3 loop acc [] = acc
  4 loop acc (x:xs) = loop (x:acc) xs
  5 
  6 
  7 rev :: [a] -> [a]
  8 rev x = loop [] x
  9 
 10 
 11 -- suml
 12 
 13 suml :: [Integer] -> Integer
 14 suml xs = loop 0 xs
 15   where 
 16     loop acc [] = acc
 17     loop acc (x:xs) = loop (acc+x) xs
 18 
 19 -- https://wiki.haskell.org/Foldr_Foldl_Foldl%27

# Exercise 2.2.6 (b)

    Note that, if we are reading backwards, we are adding a power of 2, or not (depending of the symbol value, 1 for adding and 0 for not).
    Not only this, but as the 'backwards' strings advance, we are adding consecutive powers of 2.
    There is a pattern on (N mod 5) when we add consecutives powers of 2.
    Consider the list of powers of 2: 1,2,4,8,16,32,64,128,256,512,1024....
    when we get the mod 5 of it (we can do it just looking at the last digit), we have: 1,2,4,3,1,2,4,3,1,2,4.....

    So thinking of x as the last digit of the actual power you are deciding to add, n as the modulo 5 of what you read so far, you can think of each state as "Being in n, i can add (x mod 5)",or simply call each state (n,(x mod 5)).
    So, reading 0 (not adding) would lead  to (n, (2x mod 5))
        and reading 1 (adding) would lead to (n +(x mod 5),(2x mod 5)). Build the table! 
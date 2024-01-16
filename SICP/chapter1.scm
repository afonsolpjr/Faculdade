;importing trace function, to see depth of recursion
(use-modules (system vm trace))
; Simple printing function
(define(println arg1)
    (newline)
    (display arg1)
    )
; exercise 1.2

(println(/ (+ 5 4
            (- 2
                (- 3 
                    (+ 6 
                        (/ 4 5)))))
    (* 3
        (- 6 2)
        (- 2 7))))

;exercise 1.3
; given three numbers, sum of squares of biggest 2


(define (sumsqr x y)
    (+ (square x) (square y)))

(define (sb3 a1 a2 a3)
    (cond 
        ((and (<= a3 a1) (<= a3 a2)) (sumsqr a1 a2))
        ((and (<= a2 a3) (<= a2 a1)) (sumsqr a1 a3))
        ((and (<= a1 a2) (<= a1 a3)) (sumsqr a2 a3)))
)

;exercise 1.4

;we can have operators as expressions! that means, using a expression to return a operator

(define (apab a b)
    ((if (> b 0) + -) a b))

;check

(= (apab 3 -4) (+ 3 (abs -4)))

;exercise 1.5

(define (rec) (rec))

(define (test x y) 
    (if (= x 0)
        x
        y))

; (println (test 0 (rec)))


;newton iterative square method

(define (square x)
    (* x x))

(define (improve guess x)
    ; (println ( + guess (/ x guess)))
    (/ (+ guess (/ x guess)) 2))


(define (good-enough? guess x) 
    (< (abs (- (square guess) x)) 0.001))


(define (isqrt guess x)
    (if (good-enough? guess x) 
        guess
        (isqrt (improve guess x) x) ))


(println (isqrt 1.0 2))

; exercise 1.6

; (define (new-if predicate then-clause else-clause)
; (cond (predicate then-clause)
;     (else else-clause)))



; (define (nisqrt guess x)
;     (new-if (good-enough? guess x) 
;         guess
;         (nisqrt (improve guess x) x) ))

; This leads to an unending recursion. Since it isn't a special form, at the evaluation of new-if, 
; the interpreter calls the nisqrt function again, before even evaluating the predicate.

;exercise 1.7

; (println (isqrt 1.0 8986789700123))
; stuck in loop because the average computation lost precision and is returning the same value

(println (isqrt 1.0 0.002))
; since x is close to the error margin, it increasingly become unfit to be a "good" margin

(define (good-enough2? old-guess new-guess)
    (define diff (abs (- new-guess old-guess)))
    (< (/ diff old-guess) 0.0001))


(define (nisqrt guess x)
    (if (good-enough2? guess (improve guess x)) 
        guess
        (nisqrt (improve guess x) x) ))
(println "\t exercise 1.7")
; (println (isqrt 1.0 9))
; (println (nisqrt 1.0 9))
; (println (sqrt 0.00113))
; (println (nisqrt 1.0 0.00113))
(println (nisqrt 1.0 0.00113))
(println (nisqrt 1.0 8986789700123))
;setting the stop condition to a desired ratio of change in the guess was more appropriate
(define (mysqrt x)
    (nisqrt 1.0 x))
;exercise 1.8
(println "\t exercise 1.8")

(define (better-cube-guess guess x)
    (/ (+ (/ x (square guess))
            (* 2 guess))
        3) )

(define (icbrt guess x)
    (if (good-enough2? guess (better-cube-guess guess x))
        guess
        (icbrt (better-cube-guess guess x) x)))

(println (icbrt 1.0 16))

;linear recursive factorial
(define (! x)
    (if (= x 1)
        1
        (* x (! (- x 1)))))

(println (! 6))

; linear iterative factorial

(define (! x)
    (define (iter prod c) 
        (if (> c x)
            prod
            (iter (* prod c) (+ c 1))))
    (iter 1 1))

(println (! 32))

;exercise 1.10

(define (A x y)
    (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1) 
                (A x (- y 1))))))

(println "\t exercise 1.10 (ackerman function)")
(println (A 1 10))
(println (A 2 4))
(println (A 3 3))
(println (A 2 3))

;fibbonacci

(define (fib n)
    (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1)) (fib (- n 2)) )) ))

; (println (fib 37))

(define (ifib n)
(define (it a b counter)
    (if (= counter 0)
        a 
        (it b (+ a b) (- counter 1))))
(it 0 1 n)
)

; (println (ifib 37))


; counting change for 50,25,10,5,1

(define (cc amount kinds)
    (define (first-coin kinds)
        (cond ((= kinds 1)  1)
            ((= kinds 2)  5)
            ((= kinds 3)  10)
            ((= kinds 4)  25)
            ((= kinds 5)  50)))
    (cond ((= amount 0) 1)
            ((or (< amount 0) (= kinds 0)) 0)
            (else (+ (cc amount (- kinds 1))
                    (cc (- amount (first-coin kinds)) kinds)
                )
            )
        )
    )

    (println (cc 100 5))

; exercise 1.11
;recursive
(define (fr n)
    (if (< n 3)
        n
        (+ (fr (- n 1))
            (* 2 (fr (- n 2)))
            (* 3 (fr (- n 3))))))
; (println (fr 32)) ;demora mt

; iterative

(define (fi n)
    (define (it a b c count)
        (if (= count 0)
            (+ a (* 2 b) (* 3 c))
            (it (+ a (* 2 b) (* 3 c)) a b (- count 1) )))
    (if(< n 3)
        n
        (it 2 1 0 (- n 3))))
(println (fi 32))
    
; exercise 1.12

(define (pascal l c)
    (cond ((= c 1) 1)
        ((= l c ) 1)
        (else ( + (pascal (- l 1) (- c 1))
                    ( pascal (- l 1) c)))))

(println (pascal 14 9))

; how to print 10 numbers ?

(define (for i limit)
        (println i)
        (cond ((< i 10) (for (+ i 1) limit)))
        )

(for 0 10) ;ok i can do it

; exercicio 1.15

(define (sine angle)
    (define (approx x)
        (- (* 3 x) (* 4 (* x x x))))
    (if (< angle 0.1)
        angle
        (approx (sine (/ angle 3.0)))))

(println (sine 12.15))

; exponentials

(define (**r b e)
    (if (= e 0)
        1
        (* b (**r b (- e 1)))))

(println (**r 2 16))

; iterative

(define (** b e)
    (define (it accumulator expt)
        (if (= expt 0)
            accumulator
            (it (* b accumulator) (- expt 1))))
    (it 1 e))

(println (** 2 32))

; fast logarithmic

(define (fastexp b e)
    (define (even? x)
        (= (remainder x 2) 0))
    (cond ( (= e 0) 1 )
        ( (even? e) (square (fastexp b (/ e 2))))
        ( else (* b (fastexp b (- e 1))))    ))

(println (fastexp 2 32))

; exercise 1.16 logarithmic iterative exponentiation

(define (fast-iexp b e)
    (define (even? x)
        (= (remainder x 2) 0))
    (define (it acc base expt)
        (cond ((= expt 1) (* base acc) )
            ((even? expt) (it acc (square base) (/ expt 2)))
            (else (it (* acc base) base (- expt 1))) ))
    (it 1 b e)
    )

(println (fast-iexp 6 3))

; ;checking tail recursion in REPL

; (use-modules (system vm trace))

; (define (fast-iexp b e)
;     (define (square x) (* x x))
;     (define (even? x)
;         (= (remainder x 2) 0))
;     (define (it acc base expt)
;         (cond ((= expt 1) (* base acc) )
;             ((even? expt) (it acc (square base) (/ expt 2)))
;             (else (it (* acc base) base (- expt 1))) ))
;     (it 1 b e)
;     )

; ,trace (fast-iexp 6 7)


; exercise 1.17
(define (even? x)
    ( = (remainder x 2) 0))
(define (mul a b)
(if (= b 0)
    0
    (+ a (mul a (- b 1)))))

(define (fast-mul a b)

    (define (double a)
        (+ a a))
    (define (halve a)
        (/ a 2))
    (cond 
        ((= b 0) 0)
        ((even? b) (fast-mul (double a) (halve b)))
        (else (+ a (fast-mul a (- b 1))))    )
 )

(println (fast-mul 29 13))

; exercise 1.18

(define (fast-iter-mul a b)
     (define (double a)
        (+ a a))
    (define (halve a)
        (/ a 2))
    (define (iter acc a b)
    (cond
        ((= b 0)  acc )
        ((even? b) (iter acc (double a) (halve b)))
        (else (iter (+ acc a) a (- b 1))) ))
    (iter 0 a b))


(println (fast-iter-mul 182 1237))

;exercise 1.19 fast log iterative fib


(define (logfib n)
    (define (even? x)
        (= (remainder x 2) 0))
    (define (p_t p q)
        (+ (* p p) (* q q) ))
    (define (q_t p q)
        (+ (* q q) (* 2 q p)))
    (define (iter p q a b counter)
    (cond
        ((= counter 0) b)
        ((even? counter) (iter (p_t p q) (q_t p q) a b (/ counter 2)))
        (else (iter p q (+ (* b q) (* a q) (* a p)) (+ (* b p) (* a q)) (- counter 1) )) ))
    (iter 0 1 1 0 n)
)

(println (logfib 39))


; euclidean algorithm

(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (remainder a b))))

(println (gcd 1264 32))

; factoration

(define (smallest-divisor n)
    (define (divides? a b)
        (= (remainder a b) 0))
        (define (next n)
            (if(= n 2)
                3
                (+ n 2)))
    (define (iter test-div)
        (cond 
            ((> (sqrt test-div) n) n)
            ((divides? n test-div) test-div)
            (else (iter (next test-div)))
            ))
    (iter 2))

(define (prime? n)
    (= (smallest-divisor n) n))

(println (prime? 313))


;fermat test

(define (expmod base exp m)
    (cond 
        ((= exp 0) 1)
        ((even? exp) 
            (remainder (square (expmod base (/ exp 2) m))
                 m))
        (else 
            (remainder (*   base 
                            (expmod base (- exp 1) m)) 
                        m))))

(define (fermat-test-single n)
    (define (test a)
        (= (expmod (+ a 1) n n) (+ a 1)))
    (test (random (- n 1))))

(define (fermat-test n times)
        (cond
            ((< times 0) (= 1 1) )
            ((fermat-test-single n) (fermat-test n (- times 1)))
            (else (= 0 1))))

(println (fermat-test 1271 10))

; exercise 1.22, 1.23, 1.24

(define (timed-prime-test n)
    (define (start-test-time start-time)
        (if (fermat-test n 15)
            (report-prime (- (get-internal-real-time) start-time))
            #f))
    (define (report-prime time)
        (newline)
        (display n)
        (display "***")
        (display time))
  
    (start-test-time (get-internal-real-time)))

(define (search-primes)
    (define (range n)
        (cond
            ((= n 1) 1001)
            ((= n 2) 10001)
            ((= n 3) 900001)
            ((= n 4) 3000001)))
    (define (search-primes-range l range-count primes-found)
        (cond
            ((and (< range-count 4) (= primes-found 3)) (search-primes-range 
                                    (range (+ range-count 1))
                                    (+ range-count 1)
                                    0))
            ((= primes-found 3) #f)
            ( (timed-prime-test l) (search-primes-range
                                    (+ l 2)
                                    range-count
                                    (+ primes-found 1)))
            (else (search-primes-range
                    (+ l 2)
                    range-count
                    primes-found))))
    (search-primes-range (range 1) 1 0))
(search-primes)

;exercise 1.27

(define (carmichaelnumbers n)
    (cond 
        ((= n 1) 561 )
        ((= n 2) 1105)
        ((= n 3) 1729)
        ((= n 4) 2465)
        ((= n 5) 2821)
        ((= n 6) 6601)
        (else #f)))

(define (test-carms n)
    (define (test carm candidate)
        (cond
            ((= carm candidate) #t)
            ((= (expmod candidate carm carm) candidate)
                (test carm (+ candidate 1)))
            (else #f)))
    (display (test (carmichaelnumbers n) 2)))
(define (test-all-carms n)
    (newline)
    (display (carmichaelnumbers n))
    (display "--")
    (test-carms n)
    (display "-- prime?--")
    (display (prime? (carmichaelnumbers n)))
    (if (< n 6)
        (test-all-carms (+ n 1))))

(test-all-carms 1)
(newline)
; exercise 1.28, miller rabin


    ; modify to signal non trivial square root of 1
(define (mrexpmod base exp m)
    (define (trivial-signal n)
        (if (and    (= (remainder (square n) m) 1)
                    (not (= n 1))
                    (not (= n (- m 1)))
                    )
            0
            (remainder (square n) m)))
    (cond 
        ((= exp 0) 1)
        ((even? exp) 
            (trivial-signal (mrexpmod base (/ exp 2) m)))
        (else 
            (remainder (*   base 
                            (mrexpmod base (- exp 1) m)) 
                        m))))

; will try 15 random numbers
(define (millrab n count)
    (define (test a n)
        (= (mrexpmod a (- n 1) n) 1))
    (cond   ((> count 15) #t)
            (   (test (+ (random (- n 1)) 1) n)
                (millrab n (+ count 1)))
            (else #f)))

(define (mr-start start p-found primes-wanted)    
    (cond   (   (and    (< p-found primes-wanted)
                        (millrab start 0))
                (and    (println start)
                        (display "--")
                        (display "#t")
                        (mr-start   (+ start 1)
                                    (+ p-found 1)
                                    primes-wanted)))
            (   (< p-found primes-wanted)
                (mr-start (+ start 1) p-found primes-wanted))
        
        ))

(mr-start 99999 0 5 )


(define (sum a b term next)
    (if (> a b)
        0
        (+  (term a)
            (sum (next a) b term next))))

(define (sum-integers a b)
    (sum    a b
            (lambda (x) x)
            (lambda (x) (+ x 1)) ))

(println (sum-integers 0 10))

(define (integral f a b dx)
    (*  dx
        (sum    (+  a   (/ dx 2))
                b
                f
                (lambda (x) (+ x dx)))))


(define (cube x) (* x x x))
(println "integral x^3 0<x<1 and dx=0.01, ")
(display (integral cube 0 1 0.001))

(define (simpson f a b n)
    (let ( ( h (/ (- b a ) n)))
        (define (sum-terms k)
        (cond
            (   (and (even? k) (< k n))
                (+  (*   2 (f (+ a (* k h))))
                    (sum-terms (+ k 1))))
            (   (< k n)
                (+  (*   4 (f (+ a (* k h))))
                    (sum-terms (+ k 1))))
            (else 0)))
    (*  (/ h 3.0)
        (+  (f a)
            (f b)
            (sum-terms 1)))))

(println (simpson cube 0 1 10))

; exercise 1.30
(define (sum a b term next)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (+ result (term a)))))
    (iter a 0))

(println (sum 0 10 (lambda(x) x) (lambda(x) (+ x 1))))
; exercise 1.31
(define (producti a b term next)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (* (term a) result))))
    (iter a 1))
(define (productr a b term next)
    (if (> a b)
        1
        (*  (term a)
            (productr (next a) b term next))))
(define (fat a)
    (producti 1 a (lambda(x) x) (lambda(x) (+ x 1))))
(define (fatr a)
    (productr 1 a (lambda(x) x) (lambda(x) (+ x 1))))
(println (fat 6))
(println (fatr 6))

    ;defining pi-prod

(define (piprod a)
    (producti   2   
                a
                (lambda(x) (/ (square x) (* (- x 1) (+ x 1))))
                (lambda(x) (+ x 2))))

(println (* (piprod 10000) 2.0))

; exercise 1.32

(define (accumulater combiner null-value a b term next)
    (if (> a b)
        null-value
        (combiner   (term a)
                    (accumulater combiner null-value (next a) b term next))))

(define (accumulatei combiner null-value a b term next)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (combiner (term a) result))))
    (iter a null-value))

; realmente é isso msm

(define (sum a b term next)
    (accumulatei + 0 a b term next))

(define (sum_integers a b)
    (sum a b (lambda(x)x) (lambda(x) (+ x 1))))

(println (sum_integers 0 10))

(define (product a b term next)
    (accumulatei * 1 a b term next))
(define (fat a)
    (product 1 a (lambda(x) x) (lambda(x) (+ x 1))))
(println (fat 6))

; exercise 1.33

(define (filtered-accumulate filter combiner null-value a b term next)
    (define (iter a result)
        (cond   ((> a b) result)
                ((filter a) (iter (next a) (combiner (term a) result)))
                (else (iter (next a) result))))
    (iter a null-value))

(define (miller_rabin n)
    (millrab n 0))

(define (sum_sq_primes a b)
    (filtered-accumulate miller_rabin + 0 a b (lambda(x) ( * x x)) (lambda(x) (+ x 1))))

(println (sum_sq_primes 2 15))
(define (relative_prime? a b)
    (= (gcd a b) 1))

(define (prod_rel_p n)
    (define (relative_prime_to_n? a)
        (relative_prime? n a))
    (filtered-accumulate relative_prime_to_n? * 1 1 (- n 1) (lambda(x) x) (lambda(x) (+ x 1))))

(println (prod_rel_p 8))

; pisum converges to pi/8
(define (pi_sum a b)
    (accumulatei + 0 a b    
                    (lambda(x) (/ 1.0 (* x (+ x 2))))
                    (lambda(x) (+ x 4))))

(println (* 8 (pi_sum 1 1000)))

;exercise 1.34
(define (f g)
    (g 2))
(println (f f)) ; this goes to the expression (2 2). and 2 is not a procedure
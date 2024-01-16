; Simple printing function
(define(println arg1)
    (display arg1)
    (newline))
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
(define (square x)
    (* x x))

(define (sumsqr x y)
    (+ (square x) (square y)))

(define (sb3 a1 a2 a3)
    (cond 
        ((and (<= a3 a1) (<= a3 a2)) (sumsqr a1 a2))
        ((and (<= a2 a3) (<= a2 a1)) (sumsqr a1 a3))
        ((and (<= a1 a2) (<= a1 a3)) (sumsqr a2 a3)))
)


#lang scheme
(provide fib-tail)  ; makes this available to other modules

(define fib-tail
  (lambda (x)
    (fib-tail-acc x 0 1)))
(define fib-tail-acc
  (lambda (x f2 f1)
    (if (<= x 0)
        f2
        (fib-tail-acc (- x 1) f1 (+ f1 f2)))))

; not provided to including source 
(define (fib x)
  (if (<= x 2)
      1
(+ (fib (- x 1)) (fib (- x 2)))))

(fib 10)
(fib-tail 10)
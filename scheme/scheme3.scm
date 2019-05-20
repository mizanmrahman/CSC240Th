#lang scheme
(define abs
  (lambda (x)
    (if (negative? x)
        (- x)
        x)
    ))

(define (increment a) (+ a 1))  ;note that a has local scope
((lambda (x) (+ x 1)) 7)
(define increment_lambda
  (lambda (x)
    (+ x 1)))

(define x 10)
(increment 3)
(increment x)
(increment_lambda 10)

(lambda (x) (* x 2))
((lambda (x) (* x 2)) 10)

(define (do this toThat) (this toThat))
(do increment 8)
(do (lambda (x) (* x 2)) 10)

; multi-conditional procedures
(define grade 
  (lambda (n)
    (cond
      ((>= n 900) 'A)
      ((>= n 800) 'B)
      ((>= n 700) 'C)
      ((>= n 600) 'D)
      (else 'F))))

(grade 100)
(grade 950)
(grade 899)

"Multiply-all"
(define multiply-all
  (lambda (lst)
    (if (null? lst)
        1
        (* (car lst) (multiply-all (cdr lst))))))
(multiply-all '(1 2 3 4))

(newline)
"Reduce"
(define red
  (lambda (operator base-case lst)
    (if (null? lst)
        base-case
        (operator (car lst) (red operator base-case (cdr lst))))))

(red + 0 '(1 2 3 4))
(red * 1 '(1 2 3 4))

(define sum-all
  (lambda (lst)
    (red + 0 lst)))
(sum-all '(1 2 3 4))

(define mult-all
  (lambda (lst)
    (red * 1 lst)))
(mult-all '(1 2 3 4))

(define double-lst
  (lambda (lst)
    (red (lambda (x y) (cons (* 2 x) y)) '() lst)))
(double-lst '(1 2 3 4))

"length"
(red (lambda (x y) (+ 1 y)) 0 '(1 2 3 4))
"square list"
(red (lambda (x y) (cons (* x x) y)) '() '(1 2 3 4))
"get-odds"
(red (lambda (x y) (if (= 0 (remainder x 2)) y (cons x y))) '() '(1 2 3 4 5 6 7 8 9))
"reverse"
(red (lambda (x y) (append y (list x))) '() '(1 2 3 4))


(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13))
(define lstn '(0 -1 2 -3 4 -5 6 -7 8 -9 10 -11 12 -13))
(define badlst (list "CGCC" 1 'a + 10 'hello lst '(1 2 3) '(a . b) red 8 6 -3))

(newline)
"Higher-order functions - apply"
(apply + lst)
(apply + lstn)
(apply * lst)
(apply * lstn)

(newline)
"Higher-order functions - map"
(map (lambda (x) (* x x)) lst)
(map (lambda (x) (* x x)) lstn)
(map (lambda (x) (if (> x 0) x (* -1 x))) lstn)
(map (lambda (x) (if (>= x 0) #t #f)) lst)
(map (lambda (x) (if (>= x 0) #t #f)) lstn)
(map string? badlst)

(newline)
"Higher-order functions - filter"
(filter string? badlst)
(filter pair? badlst)
(filter number? badlst)
(filter (lambda (x) (if (>= x 0) #t #f)) lstn)
(filter (lambda (x) (not (pair? x))) badlst)
(map (lambda (x) (* x x)) (filter number? badlst))
(apply + (map (lambda (x) (* x x)) (filter number? badlst)))

; function to calculate the sum of the squares of numbers in a list
(define sum-num-square
  (lambda (lst)
    (apply + (map (lambda (x) (* x x)) (filter number? lst)))))
(sum-num-square lst)
(sum-num-square badlst)

badlst
; number in badlst which are less 8 when incremented
(filter (lambda (x) (< x 8))
        (map (lambda (x) (+ x 1))
             (filter number? badlst)))
(filter (lambda (x) (< (+ x 1) 8))
        (filter number? badlst))

(apply - '(1 2 3 4))
(apply + (map - '(1 2 3 4)))

(newline)
"Newline"
(define big_num
  (lambda (n)
    (lambda (x)
      (> x n))))
(big_num 10)
(define positive? (big_num 0))
(positive? 3)
(positive? -3)
(define winner? (big_num 10))
(winner? 3)
(winner? 14)

(define increase
  (lambda (n)
    (lambda (x)
      (+ x n))))
(map (increase 10) '(1 2 3 4))

(newline)
"Define a polynomial"
(define quad
  (lambda (a b c)
    (lambda (x)
      (+ (* a x x) (* b x) c))))
(quad 1 1 1)
(define f1 (quad 1 1 1))   ; f(x) = x^2 + x + 1
(define f2 (quad 1 2 3))   ; f(x) = x^2 + 2x + 3
(define f3 (quad 2 4 2))   ; f(x) = 2x^2 + 4x + 2
(define f4 (quad 1 (/ 1 2) (/ 1 4)))   ; f(x) = x^2 + 1/2 x + 1/4
f1
(f1 2)
(f1 -2)
(f2 2)
(f2 -2)
(f3 2)
(f4 2)

(require "scheme3inc.scm")
(fib-tail 10)

(newline)
"Towers of Hanoi"
(define hanoi
  (lambda (n source center destination)
    (if (= n 1)
        (list 'Move source destination)
        (list (hanoi (- n 1) source destination center)
              (hanoi 1 source center destination)
              (hanoi (- n 1) center source destination)))))
(hanoi 3 'red 'yellow 'green)

(newline)
"let structures (scope)"
(define a 100)
a

(let
    ((a 4)
     (b 3))
  (+ a b))

(let
    ((a 4)
     (b (+ a 1)))  ; a comes from the outer scope
  (+ a b))

(let
    ((a 4))
  (let
      ((b (+ a 1)))  ; a comes from the inner scope
    (+ a b)))

; You can make thigns confusing
(let
    ((x 9))
  (let
      ((x 3)
       (y (* 5 x)))
    (+ x y)))

(define let-test
  (lambda (x)
    (let
        ((a (* 2 x))
         (b (+ 1 x))
         (c 5))
      (+ x a b c))))
(let-test 10)

(define habitat-material
  (lambda (height radius thickness)
    (let
        ( (pi 3.14159265) )
          (let
              ( (cylinder_volume
                 (lambda (r h)
                   (* h (* pi (* r r))))))
            (- 
             (cylinder_volume radius height)
             (cylinder_volume (- radius thickness) (- height (* 2 thickness))))))))
(habitat-material 10 5 1)

(let
    ((+ 10)
     (- 4)
     (* -))
  (* + -))

(newline)
"lambda->let, let->lambda"
(let
    ((a 4)
     (b 5))
  (+ a b))

((lambda (a b) (+ a b)) 4 5)


((lambda (x y) (+ (* x x) (* y y))) 3 4)
(let
    ((x 3)
     (y 4))
  (+ (* x x) (* y y)))

(newline)
"Advanced topics - not required for projet or final"
"case-lambda"
(define hello
  (case-lambda
    (() "Hello, world!")
    ((name) (string-append "Hello, " name))))
(hello)
(hello "John")

(define multiple-of-2-and-5?
  (lambda (n)
    (match (list (remainder n 2) (remainder n 5))
      ((list 0 0) #t)  ; both remainders are 0
      ((list _ 0) "Divisible only by 5")
      ((list 0 _) "Divisible only by 2")
      (_ #f))))
(multiple-of-2-and-5? 20)
(multiple-of-2-and-5? 15)
(multiple-of-2-and-5? 17)
(multiple-of-2-and-5? 8)

#lang scheme
"Review"
(define a 1)
(define b a)
(define c (+ a b))
a
b
c

(* -1 c)
(- c)
(- (- c))

(define opposite
  (lambda (x)
    (- x)))
(opposite 10)
(opposite -10)
(opposite (opposite 12))

(newline)
"null"
null
(null? 3)
(null? 0)
;(null? ())
(null? null?)
(null? null)
(null? '())

(newline)
"Tail recursive Fibonacci implementation"
(define fib-tail
  (lambda (x)
    (fib-tail-acc x 0 1)))
(define fib-tail-acc
  (lambda (x f2 f1)
    (if (<= x 2)
        (+ f1 f2)
        (fib-tail-acc (- x 1) f1 (+ f1 f2)))))
(fib-tail 10)

(newline)
"Elements in a list"
(define isit-lst0 (+ 2 3))
(define isit-lst1 '(+ 2 3))
(define isit-lst2 (list + 2 3))
(define isit-lst3 (list (+ 2 3 )))
(define isit-lst4 (list '(+ 2 3 )))
isit-lst0
isit-lst1
isit-lst2
isit-lst3
isit-lst4

(length isit-lst4)
(length (car isit-lst4))
(car isit-lst1)
(car isit-lst2)
;((car isit-lst1) 8 9 10)
((car isit-lst2) 8 9 10)
;       +               2                 3
((car isit-lst2) (cadr isit-lst2) (caddr isit-lst2))

(newline)
"More lists"
(define exlst0 (list 2 3))
(define exlst1 (list list 2 3))
(define exlst2 (list list 2 3 (list + 2 3) (+ 2 3)))
(define exlst3 '(list 2 3 (list + 2 3) (+ 2 3)))
exlst0
exlst1
exlst2
exlst3


(newline)
"Conditional statements"
(define what-is-it?
  (lambda (x)
    (cond
      ((not (number? x)) "Not a number")
      ((< x 0) "Negative")
      ((= x 0) "Zero")
      (else "Positive"))))
(what-is-it? 2)
(what-is-it? +)
(what-is-it? -4)

(define return-something
  (lambda (x)
    (cond
      ((> x 11) 10)
      ((= (remainder x 2) 0) 2)
      ((> x 5) 5)
      (#t 0))))
(return-something 20)
(return-something 8)
(return-something 7)
(return-something 3)

(newline)
"Recursion"
(define increment
  (lambda(x)
    (+ x 1)))
(define decrement
  (lambda (x)
    (- x 1)))
(increment 10)
(decrement 10)
(define recursive-add
  (lambda (x y)
    (if (zero? y)
        x
        (recursive-add (increment x) (decrement y)))))
(recursive-add 3 4)
(recursive-add 15 10)

(define recursive-mult
  (lambda (x y)
    (recursive-mult-helper x 0 y)))
(define recursive-mult-helper
  (lambda (x n y)
    (if (zero? y)
        n
        (recursive-mult-helper x (recursive-add x n) (decrement y)))))
(recursive-mult 3 4)


(newline)
"Lists"
(car '(a))
(cdr '(a))
(cons 'b '(a))
(define lst '(1 2 3 4))
(car lst)
(cdr lst)
(cons 0 lst)
(car (cons 0 lst))
(cdr (cons 0 lst))
(cons '(a b c) lst)
(cons lst lst)
(append '(a b c) lst)
(append lst lst)
(append lst (cons lst lst))

(newline)
"List procedures"
lst
(define non-empty-list?
  (lambda (lst)
    (not (or (not (list? lst)) (null? lst)))))
(non-empty-list? '())
(non-empty-list? lst)

(define do-nothing
  (lambda (lst)
    (if (not (non-empty-list? lst))
        lst
        (cons (car lst) (do-nothing (cdr lst))))))
(do-nothing '())
(do-nothing lst)

"Check if something is a list of atoms - from The Little Schemer"
(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))
(define lat?
  (lambda (lst)
    (cond
      ((null? lst) #t)
      ((atom? (car lst)) (lat? (cdr lst)))
      (else #f))))
(lat? '(1 2 3 4))
(lat? '(a b c))
(lat? '((1 2 3) (a b c)))

(define member?
  (lambda (ele lst)
    (cond
      ((null? lst) #f)
      ((eq? (car lst) ele) #t)
      ((member? ele (cdr lst)) #t)
      (else #f))))
(member? 3 '(1 2 3 4))
(member? 5 '(1 2 3 4))
(member? 4 '(1 2 (3 4) 5))
(member? 5 '(1 2 (3 4) 5))

"Remove an element from a list - from The Little Schemer"
(define rember
  (lambda (ele lst)
    (cond
      ((null? lst) '())
      ((eq? (car lst) ele) (cdr lst))
      (else (cons (car lst) (rember ele (cdr lst)))))))
(rember 3 '(1 2 3 4))
(rember 1 '(1 2 3 4))
(rember 5 '(1 2 3 4))

"Replace an element in a list"
(define replace
  (lambda (ele lst rep)
    (cond
      ((null? lst) '())
      ((eq? (car lst) ele) (cons rep (replace ele (cdr lst) rep)))
      (else (cons (car lst) (replace ele (cdr lst) rep))))))
(replace 4 '(1 2 3 4 3 2 1) 5)
(replace 1 '(1 2 3 4 3 2 1) -1)
(replace 3 '(1 2 3 4 3 2 1) 'three)
(replace 'b '(a b c a b c d e f) 'B)

"Add two list of numbers"
(define addlists
  (lambda (lst1 lst2)
    (cond
      ((null? lst1) lst2)
      ((null? lst2) lst1)
      (else (cons (+ (car lst1) (car lst2)) (addlists (cdr lst1) (cdr lst2)))))))
(addlists '(1 2 3 4) '(10 20 30 40))
(addlists '(1 2 3 4 5 6) '(1 1 1 1))
(addlists '(1 2 3 4) '(1 1 1 1 1 1 1))

"Generate a list of numbers up to n"
(define numlist
  (lambda (n)
    (if (< n 1)
        '()
        (append (numlist (- n 1)) (list n)))))
(numlist 4)

"Sum the elements of a list"
(define sumlist
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sumlist (cdr lst))))))
(sumlist lst)
(sumlist '(-1 2 3 -4 7 -3 9 -4))
(sumlist (cons 10 lst))

"Double each element in the list"
(define double
  (lambda (x)
    (* 2 x)))
(define doublelist
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (double (car lst)) (doublelist (cdr lst))))))
(doublelist lst)
(doublelist '(-1 2 3 -4 7 -3 9 -4))
(doublelist (cons 10 lst))

"The sum of the double of each element in the list"
(define sumdoublelist
  (lambda (lst)
    (if (null? lst)
        0
        (+ (double (car lst)) (sumdoublelist (cdr lst))))))
(sumdoublelist lst)

(define better-sumdoublelist
  (lambda (lst)
    (sumlist (doublelist lst))))
(better-sumdoublelist lst)

"Duplicate each element of the list"
(define duplicatelist
  (lambda (lst)
    (if (null? lst)
      '()
      (cons (car lst) (cons (car lst) (duplicatelist (cdr lst)))))))
(duplicatelist lst)

"Return list with only numbers"
(define onlynums
  (lambda (lst)
    (if (null? lst)
        '()
        (if (number? (car lst))
            (cons (car lst) (onlynums (cdr lst)))
            (onlynums (cdr lst))))))
(onlynums '('hello "world"))
(onlynums (list a b c 'd 'e 'f 1 2 3 'hello '(4 5 6) + - (+ 2 3)))
(duplicatelist (onlynums (list a b c 'd 'e 'f 1 2 3 'hello '(4 5 6) + - (+ 2 3))))
(sumdoublelist (onlynums (list a b c 'd 'e 'f 1 2 3 'hello '(4 5 6) + - (+ 2 3))))

(newline)
"Pairs"
(cons 1 '(2))
(cons 1 2)
(list? (cons 1 '(2)))
(list? (cons 1 2))
(pair? (cons 1 '(2)))
(pair? (cons 1 2))
(car '(1 . 2))
(cdr '(1 . 2))
(define pair1 '(a . b))     ; [ a . b ]
(define pair2 '(a . ()))   ; [ a . '() ] => (a)
(define pair3 '(a . (b)))   ; [ a . [ b . '() ] ] => (a b)
pair1
pair2
pair3
(car pair1)
(cdr pair1)
(cons 'a 'b)
(cons 'a '())
(cons 'a (cons 'b '()))

;example of pairs
'(30, 90)  ;lat/long
'(neworleans . (30 . 90))
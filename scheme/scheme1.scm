#lang scheme

; Imperative style:
;   x = something
;   y = change(x)
;   result = calculate(y)

; Functional style:
;   calculate(change(something))

; A Scheme form is smoething you ask Scheme to evaluate

1
"Hello, World!"
(+ 1 2)
(+ 1 2 3)
(= 1 (- 3 2) (+ -4 5))

; Comments start with semicolon
#;(Comment out an entire form "#;")
#;(define i-am-ignored
    (lambda (x)
      (* x 0)))

(newline)
"Checking if a value is an atom"
(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))
(atom? 3)
(atom? "Atom")
(atom? 'Atom)
(atom? (cons 1 2))
(atom? (list 1 2 3))

(define 1#$#&%FV 10)

(newline)
"Data types"
"Hello, world" ; string
'HelloWorld    ; symbol
+              ; primitive
#t             ; boolean
#f             ; boolean
#\A            ; character

(newline)
"Numeric data types:"
3              ; integer
#b101          ; binary
#o101          ; octal
#x101          ; hexidecimal
12.3           ; real
7/3            ; fractions
4+2i           ; imaginary


(newline)
"Number predicates"
"Integer"
(integer? 3)
(integer? 3.0)
(integer? 3.1)
(integer? (* 3 1/3))
(integer? (* 3 (/ 1 3)))

"Real"
(real? 3)
(real? 3.0)
(real? 2+i)
(real? 2+0i)

"Rational"
(rational? 1/3)

"Complex"
(complex? 2+i)

"Number"
(number? 5)
(number? (- 10 5))
(number? (car '(8 10 5)))
(number? "One")
(number? 'One)

(newline)
"Symbols & Strings"
(symbol? "hello")
(string? "hello")
(symbol? 'hello)
(string? 'hello)
(symbol->string 'hello)
(string->symbol "Hello")
(symbol? 5)
(symbol? '5)
(symbol? '1TwoIII)

(newline)
"Math"
(+ 10 10)
(* 10 10)
(+ 1 2)
(* 3 4)
(- 1)
(+ 1 2 3 4 5 6 7 8 9 10)
(* 1 2 3 4 5 6 7 8 9 10)
(* (/ (* 7 (- 8 2)) (/ (* 6 3) (* 2 3 2 (/ 1 2)))) 2)
(sqrt 9)
(sqrt 20)
(sqrt -1)
(/ 17 3)
(quotient 17 3)
(remainder 17 3)

(newline)
"Define x, y, & z"
(define x 10)
(define y 20)
(define (z) 30)
x
y
z
(z)
(+ 2 x)
(* x (/ y 6))
(= x 12)
(= 30 (z))
(= x (+ 15 -5))

(newline)
"Defining procedures"
(* 3 x) ; Scheme form
(lambda (x) (* 3 x))      ; unnamed procedure
((lambda (x) (* 3 x)) 5)
((lambda (x) (* 3 x)) x)  ; be careful with scope!
(define trip      ; define associates a name with a form
  (lambda (x)     ; lambda defines a procedure
    (* 3 x)))     ; this form associates the name "trip" with the lambda expresssion
trip
(trip 9)
(trip y)
(+ 1 x (trip 5))

"Defining a procedure with 2 parameters"
(define addem
  (lambda (a b)
    (+ a b)))
addem
(addem x y)
(addem 10 (addem 20 30))

(newline)
"Function as a parameter"
(define increment
  (lambda (x)
    (+ x 1)))
(increment 8)
(increment (increment (increment (increment 0))))
(define do
  (lambda (this that)
    (this that)))
(do increment 10)
(do - 20)
(do trip 27)
(do integer? 8)
(do (lambda (x) (* x (+ x 1))) 3)
;(do 10 20)   ; 10 is not a procedure
;(do addem 1) ; airity mismatch - addem takes 2 procedures

(newline)
"Conditionals"
(if (> 3 2) 'bigger 'smaller)
(if (< 3 2) 'bigger 'smaller)
x
(if (= x 10) (+ x 5) (do trip x))
(if (= x 12) (+ x 5) (do trip x))
(define director
  (lambda (k)
    (cond
      ((eq? k "Goodfellas") "Martin Scorsese")
      ((eq? k "Inception") "Christopher Nolan")
      ((eq? k "Rear Window") "Alfred Hitchcock")
      ((eq? k "Aliens") "James Cameron")
      (else "Alan Smithee"))))
(director "Inception")
(director "CSC240 the Movie")

(newline)
"Factorial"
(define fact
  (lambda (n)
    (if (<= n 1)
        1
        (* n (fact (- n 1))))))
(fact 10)
;(fact 1000)

"Tail-recursive factorial"
(define fact-tail
  (lambda (n)
    (fact-tail-acc n 1)))
(define fact-tail-acc
  (lambda (n acc)
    (if (<= n 1)
        acc
        (fact-tail-acc (- n 1) (* acc n)))))

(newline)
"Lists"
(list x y z)
(list 'x 'y 'z)
'(x y z)
(quote (x y z))
(define lst '(a b c))
(define lst2 (list 'a 2 "hello" 'world / #f + fact-tail 18 x 'y 'a #\H '(1 2 3) (+ 3 1)))
(define lst3 (quote ('a 2 "hello" 'world / #f + fact-tail 18 x 'y 'a #\H '(1 2 3) (+ 3 1))))
(define oplist (list + - * /))
lst
lst2
lst3
oplist

(newline)
"quote vs list"
(+ 1 2)       ; evaluate the operator + on the operands 1 & 2
'(+ 1 2)      ; do not evaluate, treat like a list
(list + 1 2)  ; add the addition operator, 1 & 2 to a list

(newline)
"list operations"
lst
(car lst)
(cdr lst)
(car (cdr lst))
(cdr (cdr lst))
(car (cdr (cdr lst)))
(cdr (cdr (cdr lst)))
(cdr '(1))
(car '((4 5 6)))
(car (car '((4 5 6))))
(car (cdr '(a b c)))
(cadr '(a b c))
(caddr '(a b c))

(newline)
"List with size 1"
(car '(1))
(cdr '(1))


(newline)
"Fun with car & cdr"
(define lst4 '((1 2) (3 4 (5 6)) (7 8)))
lst4
(car lst4)
(cdr lst4)
(car (car (cdr lst4)))
(cdr (car (cdr lst4)))
(car (cdr (car (cdr lst4))))
(cdr (cdr (car (cdr lst4))))
(car (cdr (cdr (car (cdr lst4)))))
(cdr (cdr (cdr (car (cdr lst4)))))
(car (car (cdr (cdr (car (cdr lst4))))))
(cdr (car (cdr (cdr (car (cdr lst4))))))
(car (cdr (car (cdr (cdr (car (cdr lst4)))))))
(cdr (cdr (car (cdr (cdr (car (cdr lst4)))))))

(newline)
"Checking equality"
(define num 8)
(= 32 32)
(= 32 (* 4 8))
(= 8 num)
"Equality checking with eq?"
(eq? 'Hello 'Hello)
(eq? 32 32)
(eq? 8 num)
(eq? 8 '8)
(eq? '(1 2 3) '(1 2 3))
"Equality checking with equal?"
(equal? 'Hello 'Hello)
(equal? 32 32)
(equal? 8 num)
(equal? 8 '8)
(equal? '(1 2 3) '(1 2 3))

(newline)
"Cool example"
oplist
(car oplist)    ; +
((car oplist) 1 2 3 4)
((cadr oplist) 24 7)  ; -
((car (cdr (cdr oplist))) 10 11 12)  ; *

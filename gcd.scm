#!/usr/bin/env guile
!#
(use-modules (ice-9 rdelim))

(define (read-number prompt)
  (display prompt)
  (force-output)
  (let ((line (read-line)))
    (if (eof-object? line)
        (begin
          (display "No input, exiting.\n")
          (exit 1))
        (let ((n (string->number line)))
          (if n
              n
              (begin
                (display "Not a number, try again.\n")
                (read-number prompt)))))))

(define (gcd-euclid a b)
  (let loop ((a (abs a)) (b (abs b)))
    (if (= b 0)
        a
        (loop b (remainder a b)))))

(define (banner line)
  (display "*** >>> ")
  (display line)
  (display " <<< ***\n"))

(define (main)
  (display "******************************\n")
  (display "***   GCD CALCULATOR       ***\n")
  (display "***   Euclidean algorithm  ***\n")
  (display "******************************\n")
  (newline)
  (let* ((a (read-number ">>> First number:  "))
         (b (read-number ">>> Second number: "))
         (g (gcd-euclid a b)))
    (newline)
    (banner "RESULT")
    (display ">>> GCD(")
    (display a)
    (display ", ")
    (display b)
    (display ") = ")
    (display g)
    (newline)
    (banner "DONE")))

(main)
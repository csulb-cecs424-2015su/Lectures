(ns fibonacci.core
  (:gen-class))

; Recursive Fibonacci
(defn fib [n]
  (cond
    (= n 0) 1
    (= n 1) 1
    :else (+ (fib (- n 1)) (fib (- n 2)))))

; Calculate fib(n) three times in serial
(defn fib3serial [n]
  (list (fib n) (fib n) (fib n)))

; Calculate fib(n) three times concurrently
(defn fib3parallel [n]
  (let [f1 (future (fib n))
        f2 (future (fib n))
        f3 (future (fib n))]
    (list @f1 @f2 @f3)))

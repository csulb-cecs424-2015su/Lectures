(ns coding-bat.core
  (:gen-class))

; Implement Clojure solutions to some problems on codingbat.com
; count-evens: return the number of even ints in the list.
(defn count-evens [coll]
  (if (= 0 (count coll))
    0
    (if (= 0 (mod (first coll) 2))
      (+ 1 (count-evens (next coll)))
      (count-evens (next coll)))))

; sum13: return the sum of the numbers in the list, ignoring the number 13 because it is unlucky.
(defn sum13 [coll]
  (if (= 0 (count coll))
    0
    (if (= 13 (first coll))
      (sum13 (next coll))
      (+ (first coll) (sum13 (next coll))))))

; has22: return true if the list has a 2 adjacent to another 2
(defn has22 [coll]
  (if (>= 1 (count coll))
    false
    (if (and (= 2 (first coll)) (= 2 (second coll)))
      true
      (has22 (next coll)))))

; big-diff: return the difference between the largest and smallest element.
(defn big-diff [coll]
  (- (apply max coll) (apply min coll)))


(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))

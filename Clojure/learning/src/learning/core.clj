(ns learning.core
  (:gen-class))

(defn mysecond [coll]
  (first (next coll)))

(defn myfind [x coll]
  (if (nil? coll)
    false
    (if (= x (first coll))
      true
      (myfind x (next coll)))))

(defn mysome [f coll]
  (if (nil? coll)
    false
    (if (f (first coll))
      true
      (mysome f (next coll)))))

(defn myevens [coll]
  (if (nil? coll)
    nil
    (if (even? (first coll))
      (cons (first coll) (myevens (next coll)))
      (myevens (next coll)))))

(defn myfilter [f? coll]
  (if (nil? coll)
    nil
    (if (f? (first coll))
      (cons (first coll) (myfilter f? (next coll)))
      (myfilter f? (next coll)))))

(defn -main
  [& args])
(ns lazy.core
  (:gen-class))

(defn mylazy []
  (println "realizing lazy value")
  (rand))

(defn -main
  [& args]
  (prn (type '(1 2 3 4 5)))
  (prn (type (range 1 6)))
  ; most functions working with lists in Clojure actually return something called
  ; a "lazy sequence", which is like a generator function in Python that delays
  ; the "realization" of its values until a value is requested.

  ; (range a b) gives all integers from a up to but not including b.
  ; (take n coll) takes the first n values from a sequence coll.
  ; how many values, then, are actually generated below?
  (prn (take 10 (range 1 1000000)))

  ; this is called lazy evaluation: delaying the creation/evaluation of values
  ; until they are actually needed.
  (println "")
  (println "")
  ; (repeatedly f) generates an infinite list of values by calling f over and
  ; over. how is this possible?
  (let [values (repeatedly mylazy)]
    (println (first values))  ; first value gets generated
    (println (take 1 values)) ; first value already generated, simply returned.
        (println (take 2 values)) ; one is already generated, so one more is needed.
    (println "")
    (println (take 5 values))
  ))

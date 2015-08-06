(ns maps.core
  (:gen-class))

; a map is a dictionary: a data structure that associates a key with a value.
; {} creates a map; adjacent values in the map declare a key-value pair.
(def film {:title "WALL-E" :year 2008 :produced-by "Jim Morris"
           :production-company "Pixar Animation Studios"
           :budget 180000000 :earnings 521300000 :running-time 98})

; a : in front of an identifier creates a "keyword". think of these as strings for now.

(defn -main
  [& args]
  (println film)

  ; we can retrieve a value from a map using the get function
  ; (get *map* *key*)
  (prn (get film :title))

  ; prn is like println, except it prints formatted in the same way the value
  ; would be formatted in code, so strings print with surrounding ""

  ; keywords are like strings, but can be used as a function as well.
  ; (:keyword *map*) is the same as (get *map* :keyword)
  (prn (:produced-by film))

  ; the assoc function can associate a new key into a map, or override an old one.
  ; maps are immutable, however... so this operation produces a NEW map
  (prn (assoc film :editor "Stephen Schaffer"))
  (prn film)

  ; the dissoc function can likewise remove a key.
  (prn (dissoc film :year))

  (def disney (list film
                   {:title "Finding Nemo" :produced-by "Graham Walters" :year 2003
                    :production-company "Pixar Animation Studios"
                    :budget 94000000 :earnings 936700000 :running-time 100}
                   {:title "The Lion King" :produced-by "Don Hahn" :year 1994
                    :production-company "Walt Disney Feature Animation"
                    :budget 45000000 :earnings 987500000 :running-time 88}))

  ; we can use map, filter, and reduce with maps
  (prn (filter #(>= (:running-time %) 90) disney)) ; all movies that ran at least 90 minutes

  (prn (map :title disney)) ; remember, keywords are functions.

  (prn (map #(double (/ (:earnings %) (:budget %))) disney)) ; earnings to budget ratios

  (prn (reduce #(+ %1 (:earnings %2)) 0 disney))
  ; a second way...
  (prn (reduce + 0 (map :earnings disney)))


  ; other useful things
  ; (sort-by *key-fn* comp coll)
  ; sorts the collection by comparing the result of (key-fn item) for each item
  ; in the collection. Uses comp to decide the ordering (<, >).

  (prn (sort-by :budget > disney)) ; sort the films by budget, decreasing order

  ; challenge: return only the titles of the movies, sorted in decreasing order by earnings



  )

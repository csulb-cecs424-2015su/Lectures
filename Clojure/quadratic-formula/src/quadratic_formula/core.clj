(ns quadratic-formula.core
  (:gen-class))

(defn quadratic-formula
  [a b c]
  (let [descr (- (* b b) (* 4 a c))]
    (cond
      (< descr 0) []
      (= descr 0) [(/ (- b) (* 2 a))]
      :else (let [sq (Math/sqrt descr)]
              [(/ (+ (- b) sq) (* 2 a))
               (/ (- (- b) sq) (* 2 a))]))))

(defn -main
  [& args]
  (println (quadratic-formula 3 -13 -10))

  (let [ans (quadratic-formula 1 0 1)]
    (println (count ans) "solutions"
             (if (pos? (count ans))
               ans
               ""))))

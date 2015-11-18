(ns blackjack.core
  (:gen-class))

(defn third [coll] (second (next coll)))

(defn new-deck []
  (for [suit (range 4)
        kind (range 1 14)]
    (list suit kind)))

(defn card-string [card]
  (let [suits ["Spades" "Clubs" "Diamonds" "Hearts"]]
    (str (case (second card)
           1 "Ace"
           11 "Jack"
           12 "Queen"
           13 "King"
           (str (second card)))
         " of " (nth suits (first card)))))

(defn new-game []
  (let [deck (shuffle (new-deck))]
    (list (list (first deck) (second deck))
          (list (third deck) (third (next deck)))
          (-> deck next next next next))))

(defn card-value [card]
  (cond (= 1 (second card)) 11
        (<= 10 (second card)) 10
        :else (second card)))

(defn hand-total [hand]
  (let [sum (reduce + 0 (map card-value hand))
        aces (count (filter #(= 1 (second %)) hand))]
    (if (or (<= sum 22) (= 0 aces))
      sum
      (- sum (* 10 (min aces (int (Math/ceil (/ (- sum 21) 10)))))))))

(defn hit [hand deck]
  (list (conj hand (first deck)) (next deck)))

(defn user-strategy [player dealer deck]
  "Lets the user decide whether to hit"
  (if (< (hand-total player) 21)
    (do (println "hit or stay?")
      (let [input (read-line)]
        (if (= "hit" input)
          (let [new-player (hit player deck)] (list (first new-player) dealer (second new-player)))
          (list player dealer deck))))
    (list player dealer deck)))

(defn dealer-strategy [player dealer deck]
  "Dealer always hits if less than 17"
  (if (< (hand-total dealer) 17)
    (let [new-hand (hit dealer deck)] (list player (first new-hand) (second new-hand)))
    (list player dealer deck)))

(defn do-turn [player dealer deck strategy]
  (strategy player dealer deck))

(defn user-turn [hand dealer deck]0
  (let [score (hand-total hand)]
    (println "Player hand:" (clojure.string/join ", " (map card-string hand))
             ";" score "points")
    (if (< score 21)
      (let [next-state (do-turn hand dealer deck user-strategy)]
        (if (not= (count hand) (count (first next-state)))
          (apply user-turn next-state)
          next-state))
      (list hand dealer deck))))

(defn dealer-turn [player dealer deck]
  (let [score (hand-total dealer)]
  (println "Dealer's hand:" (clojure.string/join ", " (map card-string dealer))
           ";" score "points")
  (let [next-state (do-turn player dealer deck dealer-strategy)]
    (if (not= (count dealer) (count (second next-state)))
      (do (println "Dealer hits")
          (apply dealer-turn next-state))
      next-state))))

(defn one-game [player dealer deck]
  (println "Dealer is showing" (card-string (first dealer)))
  (let [end-game (apply dealer-turn (user-turn player dealer deck))
        dealer-score (hand-total (second end-game))
        player-score (hand-total (first end-game))]
    (println (if (and (<= player-score 21) (> player-score dealer-score))
               "Player wins!"
               (if (= player-score dealer-score)
                 "Tie game!"
                 "Dealer wins!")))))

(defn -main
  [& args]
  (apply one-game (new-game)))

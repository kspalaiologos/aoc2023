(def l (str:lines (io:get-file "input.txt")))
(defun p1h (x) (decode 10
	([tie car car@reverse] (filter #0
		(foldl1 + (transpose@:* (tie@range 1 10)
			(parse-number@:str:explode@outer-product = x "123456789")))))))
(io:writeln (foldl1 + (:p1h l)))
(def a '("one" "two" "three" "four" "five" "six" "seven" "eight" "nine" "1" "2" "3" "4" "5" "6" "7" "8" "9"))
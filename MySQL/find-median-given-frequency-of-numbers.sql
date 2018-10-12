# Time:  O(nlogn)
# Space: O(n)

SELECT AVG(n.Number) AS median 
FROM Numbers n LEFT JOIN
(
SELECT Number, @prev := @count AS prevNumber, (@count := @count + Frequency) AS countNumber
FROM Numbers, 
(SELECT @count := 0, @prev := 0, @total := (SELECT SUM(Frequency) FROM Numbers)) temp ORDER BY Number
) n2
ON n.Number = n2.Number
WHERE 
(prevNumber < floor((@total+1)/2) AND countNumber >= floor((@total+1)/2))
OR
(prevNumber < floor((@total+2)/2) AND countNumber >= floor((@total+2)/2))



# Time:  O(nlogn)
# Space: O(n)

WITH total_cte AS
(
  SELECT DISTINCT visited_on, 
         SUM(amount) OVER (ORDER BY visited_on
                           RANGE BETWEEN INTERVAL 6 DAY PRECEDING
                           AND CURRENT ROW) AS amount
  FROM Customer
)

SELECT visited_on, amount, ROUND(amount/7, 2) AS average_amount
FROM total_cte as a
INNER JOIN
(SELECT MIN(visited_on) as min_visited_on FROM total_cte) as b
ON DATEDIFF(visited_on, min_visited_on) >= 6;

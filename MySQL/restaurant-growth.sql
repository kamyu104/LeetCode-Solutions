# Time:  O(nlogn)
# Space: O(n)

WITH total_cte AS
(
  SELECT visited_on, 
         SUM(amount)  OVER (ORDER BY visited_on
                            RANGE BETWEEN INTERVAL 6 DAY PRECEDING
                            AND CURRENT ROW) AS amount,
         DENSE_RANK() OVER (ORDER BY visited_on) AS rnk
  FROM Customer
)
SELECT DISTINCT visited_on, amount, ROUND(amount/7, 2) AS average_amount
FROM total_cte
WHERE rnk >= 7;

# Time:  O(n^2)
# Space: O(n)
SELECT a.visited_on                AS visited_on, 
       SUM(b.day_sum)              AS amount, 
       ROUND(AVG(b.day_sum), 2)    AS average_amount 
FROM
(
    SELECT visited_on, SUM(amount) AS day_sum 
    FROM   customer 
    GROUP  BY visited_on
    ORDER  BY NULL
) a 
LEFT JOIN
(
    SELECT visited_on, SUM(amount) AS day_sum 
    FROM   customer 
    GROUP  BY visited_on
    ORDER  BY NULL
) b 
ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6 
GROUP  BY a.visited_on 
HAVING COUNT(b.visited_on) = 7 
ORDER  BY NULL;

# Time:  O(n^2)
# Space: O(n)

SELECT a.visited_on             AS visited_on, 
       Sum(b.day_sum)           AS amount, 
       Round(Avg(b.day_sum), 2) AS average_amount 
FROM   (SELECT visited_on, 
               Sum(amount) AS day_sum 
        FROM   customer 
        GROUP  BY visited_on) a 
       LEFT JOIN (SELECT visited_on, 
                         Sum(amount) AS day_sum 
                  FROM   customer 
                  GROUP  BY visited_on) b 
              ON Datediff(a.visited_on, b.visited_on) BETWEEN 0 AND 6 
GROUP  BY a.visited_on 
HAVING Count(b.visited_on) = 7 


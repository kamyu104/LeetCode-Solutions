# Time:  O(n)
# Space: O(n)

WITH cte 
     AS (SELECT box_id, 
                (a.apple_count  + IFNULL(b.apple_count,  0)) AS apple, 
                (a.orange_count + IFNULL(b.orange_count, 0)) AS orange 
         FROM   boxes a 
                LEFT JOIN chests b 
                       ON a.chest_id = b.chest_id) 
SELECT Sum(apple)  AS apple_count, 
       Sum(orange) AS orange_count 
FROM   cte;

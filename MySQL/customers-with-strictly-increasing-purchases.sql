# Time:  O(n), assumed using hash join
# Space: O(n)

WITH year_cte AS (
    SELECT  customer_id, 
            YEAR(order_date) AS year, 
            SUM(price) AS total 
    FROM Orders
    GROUP BY customer_id, year
    ORDER BY NULL
)

SELECT a.customer_id
FROM year_cte a 
     LEFT JOIN year_cte b
     ON b.customer_id = a.customer_id AND b.year = a.year + 1
GROUP BY a.customer_id
HAVING SUM(a.total >= IFNULL(b.total, 0)) = 1
ORDER BY NULL;

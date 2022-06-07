# Time:  O(nlogn)
# Space: O(n)

WITH consecutive_cte AS (
    SELECT product_id, 
           YEAR(purchase_date) AS curr_year,
           LEAD(YEAR(purchase_date), 1) OVER(PARTITION BY product_id
                                             ORDER BY YEAR(purchase_date)) - YEAR(purchase_date) AS year_diff
    FROM orders
    GROUP BY 1, 2
    HAVING COUNT(order_id) >= 3
    ORDER BY NULL
)
 
SELECT DISTINCT product_id
FROM consecutive_cte
WHERE year_diff = 1;

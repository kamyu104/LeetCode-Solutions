# Time:  O(nlogn)
# Space: O(n)

WITH spending_cte AS (
    SELECT s.user_id,
           s.product_id,
           RANK() OVER(PARTITION BY s.user_id ORDER BY SUM(s.quantity * p.price) DESC) AS rnk
    FROM Sales s INNER JOIN Product p ON s.product_id = p.product_id
    GROUP BY s.user_id, s.product_id
    ORDER BY NULL
)

SELECT user_id, product_id
FROM spending_cte
WHERE rnk = 1;

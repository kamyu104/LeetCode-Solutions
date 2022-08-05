# Time:  O(m + nlogn)
# Space: O(n + m)

WITH details_cte AS (
    SELECT p1.invoice_id, p1.product_id, p1.quantity, p1.quantity * p2.price AS price
    FROM Purchases p1 INNER JOIN Products p2 ON p1.product_id = p2.product_id
), 
rank_cte AS (
    SELECT invoice_id, RANK() OVER (ORDER BY SUM(price) DESC) AS rnk
    FROM details_cte
    GROUP BY invoice_id
    ORDER BY NULL
), 
min_invoice_id_cte AS (
    SELECT MIN(invoice_id)
    FROM rank_cte
    WHERE rnk = 1
)

SELECT product_id, quantity, price
FROM details_cte
WHERE invoice_id IN (SELECT * FROM min_invoice_id_cte);

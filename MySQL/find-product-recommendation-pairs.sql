# Time:  O(n^2 * logn)
# Space: O(n^2)

WITH purchase_info_cte AS (
    SELECT p.user_id, p.product_id, i.category
    FROM ProductPurchases p INNER JOIN ProductInfo i ON p.product_id = i.product_id
)

SELECT a.product_id AS product1_id,
       b.product_id AS product2_id,
       a.category AS product1_category,
       b.category AS product2_category,
       COUNT(*) AS customer_count
FROM purchase_info_cte a
INNER JOIN purchase_info_cte b ON a.user_id = b.user_id AND a.product_id < b.product_id
GROUP BY 1, 2
HAVING COUNT(*) >= 3
ORDER BY 5 DESC, 1, 2;

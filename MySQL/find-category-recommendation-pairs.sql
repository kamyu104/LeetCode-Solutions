# Time:  O(n^2 * logn)
# Space: O(n^2)

WITH user_category_cte AS (
    SELECT a.user_id, b.category
    FROM ProductPurchases a INNER JOIN ProductInfo b ON a.product_id = b.product_id
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT a.category AS category1,
       b.category AS category2,
       COUNT(*) AS customer_count
FROM user_category_cte a CROSS JOIN user_category_cte b ON a.user_id = b.user_id AND a.category < b.category
GROUP BY 1, 2
HAVING customer_count >= 3
ORDER BY 3 DESC, 1, 2;

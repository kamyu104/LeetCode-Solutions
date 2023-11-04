# Time:  O(nlogn)
# Space: O(n)

WITH sellers_cte AS (
    SELECT u.seller_id, COUNT(DISTINCT o.item_id) AS num_items
    FROM Users u
    LEFT JOIN Orders o ON u.seller_id = o.seller_id
    LEFT JOIN Items i ON o.item_id = i.item_id
    WHERE u.favorite_brand != i.item_brand
    GROUP BY u.seller_id
    ORDER BY NULL
), seller_rank_cte AS (
    SELECT *, DENSE_RANK() OVER(ORDER BY num_items DESC) AS rk
    FROM sellers_cte
)

SELECT seller_id, num_items
FROM seller_rank_cte
WHERE rk = 1
ORDER BY 1;

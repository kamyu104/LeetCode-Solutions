# Time:  O(n^2 * logn)
# Space: O(n^2)

WITH stores_cte AS (
  SELECT s.store_id,
         s.store_name,
         s.location,
         MAX(i.price) AS max_price,
         MIN(i.price) AS min_price
  FROM stores s
  INNER JOIN inventory i ON s.store_id = i.store_id
  GROUP BY 1, 3
  HAVING COUNT(DISTINCT i.product_name) >= 3
  ORDER BY NULL
),
products_cte AS (
  SELECT i.store_id,
         s.store_name,
         s.location,
         i.quantity,
         i.product_name,
         i.price
  FROM inventory i
  INNER JOIN stores_cte s ON i.store_id = s.store_id AND (i.price = s.max_price OR i.price = s.min_price)
)

SELECT p1.store_id,
       p1.store_name,
       p1.location,
       p1.product_name AS most_exp_product,
       p2.product_name AS cheapest_product,
       ROUND(p2.quantity / p1.quantity, 2) AS imbalance_ratio
FROM products_cte p1
INNER JOIN products_cte p2 ON p1.store_id = p2.store_id AND p1.price > p2.price AND p1.quantity < p2.quantity
ORDER BY 6 DESC, 2;

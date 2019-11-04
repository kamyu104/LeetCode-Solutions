# Time:  O(n + k), n is number of customer, k is number of product
# Space: O(n + k)

SELECT customer_id
FROM customer
GROUP BY customer_id
HAVING count(DISTINCT product_key)=
  (SELECT count(DISTINCT product_key)
   FROM product)
ORDER BY NULL

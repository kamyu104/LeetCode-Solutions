# Time:  O(n)
# Space: O(n)

WITH product_count_cte AS
  (SELECT c.customer_id,
          o.product_id,
          p.product_name,
          count(c.customer_id) AS product_cnt
   FROM Customers c,
        Orders o,
        Products p
   WHERE c.customer_id = o.customer_id
     AND o.product_id = p.product_id
   GROUP BY c.customer_id,
            o.product_id
   ORDER BY NULL)
, max_product_count_cte AS
  (SELECT customer_id,
          max(product_cnt) AS product_cnt
   FROM product_count_cte
   GROUP BY customer_id
   ORDER BY NULL)

SELECT a.customer_id,
       a.product_id,
       a.product_name
FROM product_count_cte a
INNER JOIN max_product_count_cte b
ON a.customer_id = b.customer_id AND
   a.product_cnt = b.product_cnt;

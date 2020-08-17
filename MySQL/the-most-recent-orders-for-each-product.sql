# Time:  O(nlogn)
# Space: O(n)

SELECT p.product_name,
       p.product_id,
       o.order_id,
       o.order_date
FROM Products p
INNER JOIN
  (SELECT product_id,
          MAX(order_date) AS first_order_date
   FROM Orders
   GROUP BY product_id) tmp
ON tmp.product_id = p.product_id
INNER JOIN Orders o
ON p.product_id = o.product_id AND tmp.first_order_date = o.order_date
ORDER BY p.product_name,
         p.product_id,
         o.order_id;

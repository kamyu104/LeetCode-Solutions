# Time:  O(n)
# Space: O(n)

SELECT a.customer_id,
       a.name
FROM Customers AS a
INNER JOIN
  (SELECT *
   FROM Orders
   WHERE order_date BETWEEN "2020-06-01" AND "2020-07-31" ) AS b
ON a.customer_id = b.customer_id
INNER JOIN Product AS c
ON b.product_id = c.product_id
GROUP BY a.customer_id
HAVING SUM(CASE
               WHEN LEFT(b.order_date, 7) = "2020-06" THEN c.price * b.quantity
               ELSE 0
           END) >= 100
AND    SUM(CASE
               WHEN LEFT(b.order_date, 7) = "2020-07" THEN c.price * b.quantity
               ELSE 0
           END) >= 100
ORDER BY NULL;

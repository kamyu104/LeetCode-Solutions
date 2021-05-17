# Time:  O(n)
# Space: O(n)

WITH cte AS
  (SELECT order_id,
          AVG(quantity) AS avg_quantity,
          MAX(quantity) AS max_quantity
   FROM OrdersDetails
   GROUP BY order_id
   ORDER BY NULL)
  
SELECT order_id
FROM cte
WHERE max_quantity >
    (SELECT MAX(avg_quantity) AS max_avg_quantity
     FROM cte);

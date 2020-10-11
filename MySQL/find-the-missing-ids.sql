# Time:  O(n^2)
# Space: O(n)

WITH RECURSIVE Seq AS
  (SELECT 1 AS continued_id
   UNION ALL SELECT continued_id + 1
   FROM Seq
   WHERE continued_id <
       (SELECT MAX(customer_id)
        FROM Customers) )

SELECT continued_id AS ids
FROM Seq s
WHERE NOT EXISTS
    (SELECT customer_id
     FROM Customers c
     WHERE c.customer_id = s.continued_id);
 

# Time:  O(m + n)
# Space: O(m + n)

SELECT c.customer_id, 
       c.customer_name 
FROM   customers AS c 
       INNER JOIN (SELECT customer_id, 
                          SUM(CASE 
                                WHEN product_name = 'A' THEN 1 
                                WHEN product_name = 'B' THEN 1 
                                WHEN product_name = 'C' THEN -1 
                                ELSE 0 
                              END) AS total 
                   FROM   (SELECT DISTINCT customer_id, 
                                           product_name 
                           FROM   orders) t 
                   GROUP  BY customer_id 
                   HAVING total = 2) AS o 
               ON c.customer_id = o.customer_id;

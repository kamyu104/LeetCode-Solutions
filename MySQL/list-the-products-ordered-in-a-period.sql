# Time:  O(n)  
# Space: O(n)  

SELECT p.product_name, 
       o.unit 
FROM   (SELECT product_id, 
               Sum(unit) AS unit 
        FROM   orders 
        WHERE  order_date BETWEEN '2020-02-01' AND '2020-02-29' 
        GROUP  BY product_id) o 
       INNER JOIN products p 
              ON o.product_id = p.product_id 
WHERE  o.unit >= 100 

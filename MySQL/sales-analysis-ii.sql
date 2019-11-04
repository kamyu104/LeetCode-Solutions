# Time:  O(m + n)
# Space: O(m + n)

SELECT DISTINCT buyer_id 
FROM   sales 
       INNER JOIN product 
         ON sales.product_id = product.product_id 
WHERE  product.product_name = "s8" 
       AND buyer_id NOT IN (SELECT DISTINCT buyer_id 
                            FROM   sales 
                                   INNER JOIN product 
                                     ON sales.product_id = product.product_id 
                            WHERE  product.product_name = "iphone"); 

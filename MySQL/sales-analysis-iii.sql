# Time:  O(m + n)
# Space: O(m + n)

SELECT product_id, 
       product_name 
FROM   product 
WHERE  product_id NOT IN (SELECT product_id 
                          FROM   sales 
                          WHERE  sale_date NOT BETWEEN 
                                 '2019-01-01' AND '2019-03-31'); 

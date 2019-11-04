# Time:  O(n)
# Space: O(n)

SELECT product_id, 
       Sum(quantity) AS total_quantity 
FROM   sales 
GROUP  BY product_id 
ORDER  BY NULL 

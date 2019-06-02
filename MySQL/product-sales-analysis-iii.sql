# Time:  O(n) 
# Space: O(n) 

SELECT product_id, 
       Min(year) AS first_year, 
       quantity, 
       price 
FROM   sales 
GROUP  BY product_id 
ORDER  BY NULL 

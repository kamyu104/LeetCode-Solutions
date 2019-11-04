# Time:  O(n)
# Space: O(n)

SELECT seller_id 
FROM   sales 
GROUP  BY seller_id 
HAVING Sum(price) = (SELECT Sum(price) 
                     FROM   sales 
                     GROUP  BY seller_id 
                     ORDER  BY Sum(price) DESC 
                     LIMIT  1) 
ORDER  BY NULL

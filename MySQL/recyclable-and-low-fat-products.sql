# Time:  O(n)
# Space: O(n)

SELECT product_id
FROM   Products
WHERE  low_fats = 'Y'
       AND recyclable = 'Y'
ORDER  BY NULL;

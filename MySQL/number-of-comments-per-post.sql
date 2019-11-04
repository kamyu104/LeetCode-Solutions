# Time:  O(n)
# Space: O(n)

SELECT a.sub_id                 AS post_id, 
       Count(DISTINCT b.sub_id) AS number_of_comments 
FROM   submissions a 
       LEFT JOIN submissions b 
              ON a.sub_id = b.parent_id 
WHERE  a.parent_id IS NULL 
GROUP  BY a.sub_id 
ORDER  BY NULL 

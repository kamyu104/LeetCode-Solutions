# Time:  O(nlogn)
# Space: O(n)

SELECT DISTINCT viewer_id AS id 
FROM   views 
GROUP  BY viewer_id, 
          view_date 
HAVING Count(DISTINCT article_id) > 1 
ORDER  BY id

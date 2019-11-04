# Time:  O(nlogn)
# Space: O(n)

SELECT DISTINCT author_id AS id 
FROM   views 
WHERE  author_id = viewer_id 
ORDER  BY id

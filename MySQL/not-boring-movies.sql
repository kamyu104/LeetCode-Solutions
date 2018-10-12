# Time:  O(nlogn)
# Space: O(1)

SELECT * FROM cinema
WHERE id % 2 != 0 and description != 'boring'
ORDER BY rating DESC;


# Time:  O(n)
# Space: O(1)

SELECT name
FROM customer 
WHERE referee_id is NULL OR referee_id != 2;


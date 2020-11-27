# Time:  O(nlogn)
# Space: O(n)

SELECT user_id, CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Activity
ORDER BY user_id;

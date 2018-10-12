# Time:  O(n)
# Space: O(n)

SELECT class
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5
ORDER BY NULL;


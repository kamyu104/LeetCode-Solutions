# Time:  O(n^2)
# Space: O(n)

SELECT Email FROM Person GROUP BY Email HAVING COUNT(*) > 1


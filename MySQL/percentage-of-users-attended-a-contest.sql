# Time:  O(m + nlogn)
# Space: O(n)

SELECT contest_id,
       ROUND(COUNT(user_id) * 100 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY 2 DESC, 1;

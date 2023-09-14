# Time:  O(nlogn)
# Space: O(n)

SELECT u.user_id,
       u.name,
       IFNULL(SUM(distance), 0) AS `traveled distance`
FROM Users u LEFT JOIN Rides r ON u.user_id = r.user_id
GROUP BY 1
ORDER BY 1;

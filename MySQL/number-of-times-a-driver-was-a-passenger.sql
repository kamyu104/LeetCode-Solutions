# Time:  O(n)
# Space: O(n)

SELECT d.driver_id,
       COUNT(r2.passenger_id) AS cnt
FROM   (SELECT DISTINCT r1.driver_id FROM Rides r1) d
       LEFT JOIN Rides r2 ON d.driver_id = r2.passenger_id
GROUP BY d.driver_id
ORDER BY NULL;

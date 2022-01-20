# Time:  O(p * b + blogb)
# Space: O(p * b)

WITH arrival_time_cte AS
(
    SELECT passenger_id, MIN(b.arrival_time) AS arrival_time
    FROM Passengers p
    INNER JOIN Buses b
    ON p.arrival_time <= b.arrival_time
    GROUP BY passenger_id
    ORDER BY NULL
)

SELECT bus_id, COUNT(a.arrival_time) AS passengers_cnt
FROM Buses b
LEFT JOIN arrival_time_cte a
ON b.arrival_time = a.arrival_time
GROUP BY bus_id
ORDER BY bus_id;

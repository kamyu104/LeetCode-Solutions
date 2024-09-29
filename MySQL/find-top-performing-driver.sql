# Time:  O(tlogt)
# Space: O(t)

# window function
WITH infos_cte AS (
    SELECT v.fuel_type,
           d.driver_id,
           ROUND(AVG(t.rating), 2) AS rating,
           SUM(t.distance) AS distance,
           SUM(d.accidents) AS accidents
    FROM Trips t 
    INNER JOIN Vehicles v ON t.vehicle_id = v.vehicle_id
    INNER JOIN Drivers d ON v.driver_id = d.driver_id
    GROUP BY 1, 2
    ORDER BY NULL
),
ranks_cte AS (
    SELECT fuel_type, driver_id, rating, distance,
           RANK() OVER (PARTITION BY fuel_type ORDER BY rating DESC, distance DESC, accidents) AS rnk
    FROM infos_cte
)

SELECT fuel_type, driver_id, rating, distance
FROM ranks_cte
WHERE rnk = 1
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)

WITH first_cte AS (
    SELECT driver_id,
           AVG(distance_km / fuel_consumed) AS avg
    FROM trips
    WHERE trip_date BETWEEN '2023-01-01' AND '2023-06-30'
    GROUP BY driver_id
    ORDER bY NULL
),
second_cte AS (
    SELECT driver_id,
           AVG(distance_km / fuel_consumed) AS avg
    FROM trips
    WHERE trip_date BETWEEN '2023-07-01' AND '2023-12-31'
    GROUP BY driver_id
    ORDER bY NULL
)

SELECT f.driver_id,
       d.driver_name,
       ROUND(f.avg, 2) AS first_half_avg,
       ROUND(s.avg, 2) AS second_half_avg,
       ROUND(s.avg - f.avg, 2) AS efficiency_improvement
FROM first_cte f
INNER JOIN second_cte s ON f.driver_id = s.driver_id
INNER JOIN drivers d ON f.driver_id = d.driver_id
WHERE f.avg < s.avg
ORDER BY 5 DESC, 2 ASC;

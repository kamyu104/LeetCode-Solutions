# Time:  O(d + r + tlogt)
# Space: O(d + r + t)

WITH RECURSIVE year_cte AS (
    SELECT MIN(YEAR(join_date)) year,
           MAX(YEAR(join_date)) max_year
    FROM drivers
    UNION ALL
    SELECT year + 1,
           max_year
    FROM year_cte
    WHERE year < max_year
),
year_month_cte AS (
    SELECT year,
           1 month,
           12 max_month
    FROM year_cte
    UNION ALL
    SELECT year,
           month + 1,
           max_month
    FROM year_month_cte
    WHERE month < max_month
),
total_per_month_cte AS (
    SELECT MAX(YEAR(r.requested_at)) 'year',
           MAX(MONTH(r.requested_at)) 'month',
           SUM(a.ride_distance) AS monthly_distance,
           SUM(a.ride_duration) AS monthly_duration
    FROM rides r LEFT JOIN acceptedrides a ON r.ride_id = a.ride_id
    GROUP BY LEFT(r.requested_at, 7)
)
SELECT month,
       average_ride_distance,
       average_ride_duration
FROM (
    SELECT t1.year,
           t1.month,
           ROUND(IFNULL(SUM(t2.monthly_distance) OVER w, 0)/3, 2) average_ride_distance, 
           ROUND(IFNULL(SUM(t2.monthly_duration) OVER w, 0)/3, 2) average_ride_duration
    FROM year_month_cte t1
         LEFT JOIN total_per_month_cte t2 ON t1.year = t2.year AND t1.month = t2.month
         WINDOW w AS (ORDER BY t1.year, t1.month ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING)
) tmp
WHERE year = 2020 AND month <= 10;

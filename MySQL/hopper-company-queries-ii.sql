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
drivers_count_cte AS(
    SELECT MAX(YEAR(d.join_date)) 'year',
           MAX(MONTH(d.join_date)) 'month',
           COUNT(d.driver_id) drivers_count
    FROM drivers d
    GROUP BY LEFT(d.join_date, 7)
),
working_drivers_count_cte AS (
    SELECT MAX(YEAR(r.requested_at)) 'year',
           MAX(MONTH(r.requested_at)) 'month',
           COUNT(DISTINCT a.driver_id) working_drivers
    FROM rides r LEFT JOIN acceptedrides a ON r.ride_id = a.ride_id
    GROUP BY LEFT(r.requested_at, 7)    
)

SELECT month,
       ROUND(IFNULL(working_drivers/active_drivers*100, 0), 2) AS working_percentage
FROM (
    SELECT t1.month,
           t1.year,
           IFNULL(SUM(t2.drivers_count) OVER (ORDER BY t1.year, t1.month), 0) active_drivers, 
           IFNULL(t3.working_drivers, 0) working_drivers
    FROM year_month_cte t1
         LEFT JOIN drivers_count_cte t2         ON t1.year = t2.year AND t1.month = t2.month 
         LEFT JOIN working_drivers_count_cte t3 ON t1.year = t3.year AND t1.month = t3.month
) tmp
WHERE year = 2020;

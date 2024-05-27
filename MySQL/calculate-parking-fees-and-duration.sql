# Time:  O(nlogn)
# Space: O(n)

WITH info_cte AS (
    SELECT car_id,
           lot_id,
           SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) AS duration
    FROM ParkingTransactions
    GROUP BY 1, 2
    ORDER BY NULL
), max_info_cte AS (
    SELECT car_id,
           MAX(duration) AS max_duration
    FROM info_cte
    GROUP BY 1
    ORDER BY NULL
), max_duration_lot_cte AS (
    SELECT a.car_id,
           lot_id AS most_time_lot
    FROM info_cte a INNER JOIN max_info_cte b
    ON a.car_id = b.car_id AND a.duration = b.max_duration
), total_cte AS (
    SELECT car_id,
           SUM(fee_paid) AS total_fee_paid,
           SUM(TIMESTAMPDIFF(SECOND, entry_time, exit_time)) AS total_duration
    FROM ParkingTransactions
    GROUP BY 1
    ORDER BY NULL
)

SELECT a.car_id,
       total_fee_paid,
       ROUND(total_fee_paid * 3600 / total_duration, 2) AS avg_hourly_fee,
       most_time_lot
FROM max_duration_lot_cte a INNER JOIN total_cte b   
ON a.car_id = b.car_id
ORDER BY 1;

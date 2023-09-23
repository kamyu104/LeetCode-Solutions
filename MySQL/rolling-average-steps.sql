# Time:  O(nlogn)
# Space: O(n)

WITH avg_cte AS (
    SELECT user_id, steps_date,
           COUNT(*) OVER(PARTITION BY user_id ORDER BY steps_date RANGE BETWEEN INTERVAL 2 DAY PRECEDING AND CURRENT ROW) AS cnt,
           ROUND(AVG(steps_count) OVER(PARTITION BY user_id ORDER BY steps_date RANGE BETWEEN INTERVAL 2 DAY PRECEDING AND CURRENT ROW), 2) AS rolling_average
    FROM Steps
)
SELECT user_id, steps_date, rolling_average
FROM avg_cte
WHERE cnt = 3
ORDER BY 1, 2;

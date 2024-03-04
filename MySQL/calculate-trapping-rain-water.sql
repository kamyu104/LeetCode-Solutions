# Time:  O(nlogn)
# Space: O(n)

WITH left_right_max_cte AS (
    SELECT *,
           MAX(height) OVER(ORDER BY id) AS left_max,
           MAX(height) OVER(ORDER BY id DESC) AS right_max
    FROM Heights
)
SELECT SUM(LEAST(left_max, right_max) - height) AS total_trapped_water
FROM left_right_max_cte;

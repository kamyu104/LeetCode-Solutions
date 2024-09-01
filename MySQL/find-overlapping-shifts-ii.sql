# Time:  O(n^2)
# Space: O(n^2)

# window function, combinatorics
WITH time_cte AS (
    SELECT employee_id, start_time AS time
    FROM EmployeeShifts
    UNION DISTINCT
    SELECT employee_id, end_time AS time
    FROM EmployeeShifts
), segments_cte AS (
    SELECT employee_id,
           time AS start_time,
           LEAD(time) OVER(PARTITION BY employee_id ORDER BY time) AS end_time
    FROM time_cte
), counts_cte AS (
    SELECT s.employee_id,
           s.start_time,
           s.end_time,
           COUNT(*) AS cnt
    FROM segments_cte s
    INNER JOIN EmployeeShifts e 
        ON s.employee_id = e.employee_id
    WHERE s.start_time >= e.start_time
      AND s.end_time <= e.end_time
    GROUP BY 1, 2, 3
    ORDER BY NULL
)

SELECT employee_id,
       MAX(cnt) AS max_overlapping_shifts,
       SUM(cnt * (cnt - 1) / 2 * TIMESTAMPDIFF(MINUTE, start_time, end_time)) AS total_overlap_duration 
FROM counts_cte
GROUP BY 1
ORDER BY 1;

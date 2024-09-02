# Time:  O(n^2)
# Space: O(n^2)

# line sweep
WITH events_cte AS (
    SELECT employee_id,
           start_time AS event_time,
           +1 as event_type
    FROM EmployeeShifts
    UNION ALL
    SELECT employee_id,
           end_time AS event_time,
           -1 as event_type
    FROM EmployeeShifts
    ORDER BY 1, 2, 3
), line_sweep_cte AS (
    SELECT employee_id,
           @event_count := @event_count + event_type AS event_count
    FROM events_cte, (SELECT @event_count := 0) init
), max_count_cte AS (
    SELECT employee_id,
       MAX(event_count) AS max_overlapping_shifts
    FROM line_sweep_cte
    GROUP BY 1
    ORDER BY NULL
), overlap_cte AS (
    SELECT e1.employee_id,
           TIMESTAMPDIFF(MINUTE, e2.start_time, IF(e1.end_time < e2.end_time, e1.end_time, e2.end_time)) AS overlap_duration
    FROM EmployeeShifts e1
    INNER JOIN EmployeeShifts e2
        ON e1.employee_id = e2.employee_id
    WHERE e1.start_time < e2.start_time
      AND e1.end_time > e2.start_time
), total_duration_cte AS (
    SELECT employee_id,
           SUM(overlap_duration) AS total_overlap_duration
    FROM overlap_cte
    GROUP BY 1
    ORDER BY NULL
)

SELECT c.employee_id,
       max_overlapping_shifts,
       IFNULL(total_overlap_duration, 0) AS total_overlap_duration
FROM max_count_cte c
LEFT JOIN total_duration_cte d
     ON c.employee_id = d.employee_id
ORDER BY 1;


# Time:  O(n^2)
# Space: O(n^2)
# window function, combinatorics
WITH time_cte AS (
    SELECT employee_id, start_time AS time
    FROM EmployeeShifts
    UNION
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

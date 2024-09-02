# Time:  O(nlogn)
# Space: O(n)

# line sweep
WITH events_cte AS (
    SELECT employee_id,
           start_time AS event_time,
           +1 as event_type
    FROM Tasks
    UNION ALL
    SELECT employee_id,
           end_time AS event_time,
           -1 as event_type
    FROM Tasks
    ORDER BY 1, 2, 3
), line_sweep_cte AS (
    SELECT employee_id,
           CASE WHEN @event_count = 0 THEN @start_time := event_time
                ELSE @start_time END AS start_time,
           @event_count := @event_count + event_type AS event_count,
           CASE WHEN @event_count = 0 THEN event_time
                ELSE @start_time END AS end_time
    FROM events_cte, (SELECT @event_count := 0, @start_time := 0) init
)

SELECT employee_id,
       FLOOR(SUM(TIMESTAMPDIFF(SECOND, start_time, end_time)) / 3600) AS total_task_hours,
       MAX(event_count) AS max_concurrent_tasks
FROM line_sweep_cte
GROUP BY 1
ORDER BY 1;

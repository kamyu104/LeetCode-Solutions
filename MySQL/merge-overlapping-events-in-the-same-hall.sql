# Time:  O(nlogn)
# Space: O(n)

WITH event_cte AS (
  SELECT IFNULL(start_day > MAX(end_day) OVER w, 1) AS is_new_event_start,
         hall_id,
         start_day,
         end_day
  FROM HallEvents
  WINDOW w AS (PARTITION BY hall_id 
               ORDER BY start_day ASC, end_day ASC
               ROWS BETWEEN UNBOUNDED PRECEDING AND 1 PRECEDING)
),
event_id_cte AS (
  SELECT SUM(is_new_event_start) OVER w AS event_id,
         hall_id,
         start_day,
         end_day
  FROM event_cte
  WINDOW w AS (PARTITION BY hall_id
               ORDER BY start_day ASC, end_day ASC)
)
SELECT hall_id,
       MIN(start_day) AS start_day,
       MAX(end_day) AS end_day    
FROM event_id_cte
GROUP BY hall_id, event_id
ORDER BY NULL;

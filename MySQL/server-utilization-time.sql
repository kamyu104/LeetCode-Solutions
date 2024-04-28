# Time:  O(nlogn)
# Space: O(n)

# window function
WITH diff_cte AS (
  SELECT TIMESTAMPDIFF(SECOND, status_time, (LEAD(status_time) OVER w)) AS diff,
         session_status
  FROM servers
  WINDOW w AS (PARTITION BY server_id ORDER BY status_time)
)

SELECT FLOOR(SUM(diff) / 86400) AS total_uptime_days
FROM diff_cte 
WHERE session_status = 'start';

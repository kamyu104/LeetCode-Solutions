# Time:  O(nlogn)
# Space: O(n)

WITH sessions_cte AS (
    SELECT user_id,
           session_type,
           ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY session_start) AS rnk,
           SUM(CASE WHEN session_type = 'Streamer' THEN 1 ELSE 0 END) OVER (PARTITION BY user_id) AS sessions_count
    FROM Sessions
)

SELECT user_id, sessions_count
FROM sessions_cte
WHERE rnk = 1 AND session_type = 'Viewer' AND sessions_count > 0
ORDER BY 2 DESC;

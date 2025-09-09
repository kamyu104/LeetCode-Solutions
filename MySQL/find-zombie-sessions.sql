# Time:  O(nlogn)
# Space: O(n)

SELECT session_id,
       user_id,
       TIMESTAMPDIFF(MINUTE, MIN(event_timestamp), MAX(event_timestamp)) AS session_duration_minutes,
       SUM(event_type = 'scroll') AS scroll_count
FROM app_events
GROUP BY 1, 2
HAVING session_duration_minutes > 30
AND scroll_count >= 5
AND SUM(event_type = 'click') * 5 < scroll_count
AND SUM(event_type = 'purchase') = 0
ORDER BY 4 DESC, 1;

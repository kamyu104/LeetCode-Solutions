# Time:  O(n)
# Space: O(n)

SELECT age_bucket, 
       ROUND(SUM(CASE WHEN activity_type = 'send' THEN time_spent ELSE 0 END)/SUM(time_spent)*100, 2) AS send_perc,
       ROUND(SUM(CASE WHEN activity_type = 'open' THEN time_spent ELSE 0 END)/SUM(time_spent)*100, 2) AS open_perc
FROM Activities a1
LEFT JOIN Age a2
ON a1.user_id = a2.user_id
GROUP BY 1
ORDER BY NULL;

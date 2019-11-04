# Time:  O(n)
# Space: O(n)

SELECT Round(Ifnull(Count(DISTINCT session_id) / Count(DISTINCT user_id), 0), 2) 
       AS 
       average_sessions_per_user 
FROM   activity 
WHERE  Datediff("2019-07-27", activity_date) < 30 

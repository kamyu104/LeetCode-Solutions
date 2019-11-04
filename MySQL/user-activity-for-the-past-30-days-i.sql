# Time:  O(n)
# Space: O(n)

SELECT activity_date           AS day, 
       Count(DISTINCT user_id) AS active_users 
FROM   activity 
GROUP  BY activity_date 
HAVING Datediff("2019-07-27", activity_date) < 30 
ORDER  BY NULL 

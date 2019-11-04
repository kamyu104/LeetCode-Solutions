# Time:  O(n)
# Space: O(n)

SELECT login_date, 
       Count(user_id) AS user_count 
FROM   (SELECT user_id, 
               Min(activity_date) AS login_date 
        FROM   traffic 
        WHERE  activity = 'login' 
        GROUP  BY user_id
        ORDER BY NULL) p 
WHERE  Datediff('2019-06-30', login_date) <= 90 
GROUP BY login_date
ORDER BY NULL

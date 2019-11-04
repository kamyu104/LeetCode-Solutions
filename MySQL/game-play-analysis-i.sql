# Time:  O(n)
# Space: O(n)

SELECT player_id, 
       Min(event_date) first_login 
FROM   activity 
GROUP  BY player_id 
ORDER  BY NULL 

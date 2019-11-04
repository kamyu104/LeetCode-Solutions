# Time:  O(n)
# Space: O(n)

SELECT player_id, 
       device_id 
FROM   activity 
WHERE  ( player_id, event_date ) IN (SELECT player_id, 
                                            Min(event_date) 
                                     FROM   activity 
                                     GROUP  BY player_id 
                                     ORDER  BY NULL) 

# Time:  O(n)
# Space: O(n)

SELECT Round(Count(NULLIF(a.event_date, NULL)) / Count(*), 2) fraction 
FROM   activity a 
       RIGHT JOIN (SELECT player_id, 
                          Min(event_date) event_date 
                   FROM   activity 
                   GROUP  BY player_id 
                   ORDER  BY NULL) b 
               ON Datediff(a.event_date, b.event_date) = 1 
                  AND a.player_id = b.player_id 

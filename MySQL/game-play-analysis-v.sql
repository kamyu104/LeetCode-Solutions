# Time:  O(n^2)
# Space: O(n)

SELECT install_dt, 
       Count(player_id)                             AS installs, 
       Round(Count(next_day) / Count(player_id), 2) AS Day1_retention 
FROM   (SELECT a.player_id, 
               a.install_dt, 
               b.event_date AS next_day 
        FROM   (SELECT player_id, 
                       Min(event_date) AS install_dt 
                FROM   activity 
                GROUP  BY player_id) AS a 
               LEFT JOIN activity AS b 
                      ON Datediff(b.event_date, a.install_dt) = 1
                         AND a.player_id = b.player_id ) AS t 
GROUP  BY install_dt; 

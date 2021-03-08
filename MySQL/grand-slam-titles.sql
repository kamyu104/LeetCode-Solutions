# Time:  O(n)
# Space: O(n)

WITH cte
     AS (SELECT wimbledon AS id
         FROM   championships
         UNION ALL
         SELECT fr_open AS id
         FROM   championships
         UNION ALL
         SELECT us_open AS id
         FROM   championships
         UNION ALL
         SELECT au_open AS id
         FROM   championships)
SELECT player_id,
       player_name,
       Count(*) AS grand_slams_count
FROM   players
       INNER JOIN cte
               ON players.player_id = cte.id
GROUP  BY 1, 2
ORDER  BY NULL; 

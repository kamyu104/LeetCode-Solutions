# Time:  O(n^2)
# Space: O(n^2)

WITH recommend_cte
     AS (SELECT DISTINCT a.user_id user_id,
                         b.user_id recommended_id
         FROM   listens a
                INNER JOIN listens b ON a.user_id != b.user_id AND a.day = b.day AND a.song_id = b.song_id
         GROUP  BY a.user_id,
                   b.user_id,
                   a.day
         HAVING Count(DISTINCT a.song_id) >= 3
         ORDER  BY NULL)

SELECT user_id,
       recommended_id
FROM   recommend_cte a
WHERE  NOT EXISTS
     (SELECT 1
      FROM   friendship b
      WHERE  (a.user_id = b.user1_id AND a.recommended_id = b.user2_id)
             OR
             (a.user_id = b.user2_id AND a.recommended_id = b.user1_id)); 

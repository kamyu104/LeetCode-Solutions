# Time:  O(n * l), n is the number of users, l is the number of listens
# Space: O(n * l)

SELECT DISTINCT a.user_id user1_id,
                b.user_id user2_id
FROM   friendship c
       INNER JOIN listens a ON c.user1_id = a.user_id
       INNER JOIN listens b ON c.user2_id = b.user_id AND a.day = b.day AND a.song_id = b.song_id
GROUP  BY c.user1_id,
          c.user2_id,
          a.day
HAVING Count(DISTINCT a.song_id) >= 3
ORDER  BY NULL;

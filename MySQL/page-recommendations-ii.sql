# Time:  O(n * m)
# Space: O(n * m)

WITH like_set_cte AS (
   (
    SELECT f.user2_id AS user_id,
           l.user_id AS friend_like,
           l.page_id page_id
    FROM Friendship f
    INNER JOIN Likes l ON l.user_id = f.user1_id
   )
   UNION
   (
    SELECT f.user1_id AS user_id,
           l.user_id AS friend_like,
           l.page_id page_id
    FROM Friendship f
    INNER JOIN Likes l ON l.user_id = f.user2_id)
   )
SELECT user_id,
       page_id,
       count(friend_like) friends_likes
FROM like_set_cte c
WHERE NOT EXISTS
    (SELECT CONCAT(user_id, '-', page_id)
     FROM Likes l
     WHERE l.user_id = c.user_id
       AND l.page_id = c.page_id)
GROUP BY user_id,
         page_id
ORDER BY NULL;

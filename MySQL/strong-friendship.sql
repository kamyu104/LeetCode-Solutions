# Time:  O(n^3), n is the number of users
# Space: O(n^2)

WITH friendship_cte AS
(
    SELECT * FROM Friendship
    UNION ALL
    SELECT user2_id AS user1_id, user1_id AS user2_id FROM Friendship
)

SELECT a.user1_id, a.user2_id, COUNT(*) AS common_friend
FROM Friendship AS a
INNER JOIN friendship_cte AS b
ON b.user1_id = a.user2_id
WHERE EXISTS (SELECT 1 FROM friendship_cte AS c
              WHERE c.user1_id = a.user1_id
              AND c.user2_id = b.user2_id)
GROUP BY a.user1_id, a.user2_id
HAVING common_friend >= 3
ORDER BY NULL;

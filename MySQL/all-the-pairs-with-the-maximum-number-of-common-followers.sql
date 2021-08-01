# Time:  O(n^3), n is the number of users
# Space: O(n^2)

WITH relation_cte AS
(
    SELECT  a.user_id AS user1_id, 
            b.user_id AS user2_id,
            RANK() OVER(ORDER BY COUNT(*) DESC) AS rnk
    FROM Relations a
    INNER JOIN Relations b
    ON a.follower_id = b.follower_id
    AND a.user_id < b.user_id 
    GROUP BY a.user_id, b.user_id
)
       
SELECT user1_id, user2_id
FROM relation_cte
WHERE rnk = 1;

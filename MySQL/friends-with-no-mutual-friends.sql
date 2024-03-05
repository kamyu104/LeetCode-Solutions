# Time:  O(n^2 * logn)
# Space: O(n^2)

WITH pairs_cte AS (
    SELECT user_id1 AS user_id,
           user_id2 AS friend_id
    FROM Friends
    UNION ALL 
    SELECT user_id2 AS user_id,
           user_id1 AS friend_id
    FROM Friends
), shared_cte AS (
    SELECT p1.user_id AS user_id1,
           p2.user_id AS user_id2
    FROM pairs_cte p1
    INNER JOIN pairs_cte p2
    ON p1.friend_id = p2.friend_id
)

SELECT f.user_id1, f.user_id2
FROM Friends f
LEFT JOIN shared_cte s
ON f.user_id1 = s.user_id1 AND f.user_id2 = s.user_id2
WHERE s.user_id1 IS NULL
ORDER BY 1, 2;

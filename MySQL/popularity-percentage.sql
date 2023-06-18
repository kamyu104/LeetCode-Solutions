# Time:  O(n^2)
# Space: O(n^2)

WITH friends_cte AS (
    SELECT user1, user2 FROM Friends
    UNION
    SELECT user2, user1 FROM Friends
),
users_cte AS (
  SELECT DISTINCT(user1) FROM friends_cte
)

SELECT user1,
       ROUND(COUNT(*) * 100 / (SELECT COUNT(*) FROM users_cte), 2) AS percentage_popularity
FROM friends_cte
GROUP BY 1
ORDER BY 1;

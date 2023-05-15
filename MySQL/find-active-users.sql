# Time:  O(nlogn)
# Space: O(n)

WITH active_users_cte AS (
    SELECT user_id, 
           IF (DATEDIFF(created_at, LAG(created_at, 1) OVER (PARTITION BY user_id
                                                             ORDER BY created_at)) <= 7, 1, 0) AS active
    FROM users
)

SELECT DISTINCT user_id
FROM active_users_cte
WHERE active = 1;

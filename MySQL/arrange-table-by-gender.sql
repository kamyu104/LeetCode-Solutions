# Time:  O(nlogn)
# Space: O(n)

WITH genders_cte AS (
    SELECT *,
           RANK() OVER(PARTITION BY gender ORDER BY user_id) AS rnk1,
           CASE gender
                WHEN 'female' THEN 1
                WHEN 'other'  THEN 2
                ELSE 3
           END AS rnk2
    FROM Genders
    ORDER BY NULL
)

SELECT user_id, gender
FROM genders_cte
ORDER BY rnk1, rnk2;

# Time:  O(nlogn)
# Space: O(n)

# window function
WITH count_cte AS (
    SELECT user_id,
           reaction,
           COUNT(*) AS cnt,
           SUM(COUNT(*)) OVER (PARTITION BY user_id) AS total,
           RANK() OVER (PARTITION BY user_id ORDER BY COUNT(*) DESC) AS rnk
    FROM reactions
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT user_id,
       reaction AS dominant_reaction,
       ROUND(cnt / total, 2) AS reaction_ratio
FROM count_cte
WHERE rnk = 1
AND total >= 5
AND 5 * cnt >= 3 * total
ORDER BY 3 DESC, 1;

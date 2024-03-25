# Time:  O(nlogn)
# Space: O(n)

# window function
# current expected answer is confusing, it may be wrong in the future
WITH avg_weekly_posts_cte AS (
    SELECT user_id, COUNT(*) / 4.0 AS avg_weekly_posts
    FROM Posts
    WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
    GROUP BY 1
    ORDER BY NULL
), posts_in_7_days_cte AS (
    SELECT user_id, post_date, COUNT(*) OVER w AS sevenday_posts
    FROM Posts
    WINDOW w AS (PARTITION BY user_id 
                 ORDER BY post_date
                 RANGE BETWEEN CURRENT ROW AND INTERVAL 6 DAY FOLLOWING)
    ORDER BY NULL
), posts_in_7_days_aggr_cte AS (
    SELECT user_id, SUM(sevenday_posts) AS sevenday_posts  -- `SELECT user_id, MAX(sevenday_posts) AS sevenday_posts` is more reasonable
    FROM posts_in_7_days_cte
    GROUP BY user_id, post_date
    ORDER BY NULL
), max_posts_in_7_days_aggr_cte AS (
    SELECT user_id, MAX(sevenday_posts) AS max_7day_posts
    FROM posts_in_7_days_aggr_cte
    GROUP BY 1
    ORDER BY NULL
)

SELECT user_id, max_7day_posts, avg_weekly_posts
FROM max_posts_in_7_days_aggr_cte
INNER JOIN avg_weekly_posts_cte USING (user_id)
WHERE max_7day_posts >= 2 * avg_weekly_posts
ORDER BY 1;

# Time:  O(n)
# Space: O(n)

WITH platforms_cte AS (
    SELECT 'IOS' AS platform
    UNION ALL
    SELECT 'Android'
    UNION ALL
    SELECT 'Web'
),
experiment_names_cte AS (
    SELECT 'Programming' AS experiment_name
    UNION ALL
    SELECT 'Sports'
    UNION ALL
    SELECT 'Reading'
),
platforms_and_experiments_cte AS (
    SELECT * FROM platforms_cte CROSS JOIN experiment_names_cte
)

SELECT
    a.platform,
    a.experiment_name,
    COUNT(b.platform) AS num_experiments
FROM
    platforms_and_experiments_cte a
    LEFT JOIN Experiments b
    ON a.platform = b.platform AND a.experiment_name = b.experiment_name
GROUP BY a.platform, a.experiment_name
ORDER BY NULL;

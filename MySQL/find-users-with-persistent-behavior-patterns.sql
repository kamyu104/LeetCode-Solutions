# Time:  O(nlogn)
# Space: O(n)

# window function
WITH daily_single_action_cte AS (
    SELECT user_id, action_date, action
    FROM activity
    GROUP BY 1, 2
    HAVING COUNT(*) = 1
    ORDER BY NULL
),
streaks_cte AS (
    SELECT user_id,
           action,
           action_date,
           DATE_SUB(action_date, INTERVAL ROW_NUMBER() OVER (PARTITION BY user_id, action ORDER BY action_date) DAY) AS gid
    FROM daily_single_action_cte
    ORDER BY NULL
),
streak_lengths_cte AS (
    SELECT user_id,
           action,
           COUNT(*) AS streak_length,
           MIN(action_date) AS start_date,
           MAX(action_date) AS end_date
    FROM streaks_cte
    GROUP BY 1, 2, gid
    HAVING COUNT(*) >= 5
    ORDER BY NULL
),
max_streaks_cte AS (
    SELECT user_id,
           action,
           streak_length,
           start_date,
           end_date,
           ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY streak_length DESC, start_date) AS rn
    FROM streak_lengths_cte
    ORDER BY NULL
)

SELECT user_id,
       action,
       streak_length,
       start_date,
       end_date
FROM max_streaks_cte
WHERE rn = 1
ORDER BY 3 DESC, 1;

# Time:  O(nlogn)
# Space: O(n)

WITH diff_cte AS (
    SELECT *,
           TIMESTAMPDIFF(
               HOUR,
               session_end,
               LEAD(session_start) OVER(PARTITION BY user_id, session_type ORDER BY session_start)) AS diff
    FROM Sessions
)

SELECT DISTINCT user_id
FROM diff_cte
WHERE diff <= 12
ORDER BY 1;

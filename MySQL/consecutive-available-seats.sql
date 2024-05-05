# Time:  O(nlogn)
# Space: O(n)

# window function
WITH window_cte AS (
    SELECT seat_id,
           free,
           LAG(free, 1) OVER (ORDER BY seat_id) AS free_lag,
           LEAD(free, 1) OVER (ORDER BY seat_id) AS free_lead
    FROM Cinema
)

SELECT seat_id
FROM window_cte
WHERE (free = 1 AND free_lag = 1) OR (free = 1 AND free_lead = 1)
ORDER BY 1;

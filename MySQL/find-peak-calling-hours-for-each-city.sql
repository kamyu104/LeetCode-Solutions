# Time:  O(nlogn)
# Space: O(n)

WITH call_by_hour_cte AS (
    SELECT city, 
           HOUR(call_time) AS calling_hour,
           COUNT(*) AS number_of_calls
    FROM Calls
    GROUP BY 1, 2
    ORDER BY NULL
),
rank_calling_hour_cte AS (
    SELECT *,
           DENSE_RANK() OVER (PARTITION BY city ORDER BY number_of_calls DESC) AS rnk
    FROM call_by_hour_cte
)

SELECT city, 
       calling_hour AS peak_calling_hour,
       number_of_calls
FROM rank_calling_hour_cte
WHERE rnk = 1
ORDER BY 2 DESC, 1 DESC;

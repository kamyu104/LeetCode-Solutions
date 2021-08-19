# Time:  O(n)
# Space: O(n)

WITH call_cte AS
(
    SELECT caller_id AS user_id, call_time, recipient_id
    FROM Calls
    UNION 
    SELECT recipient_id AS user_id, call_time, caller_id AS recipient_id
    FROM Calls
),
first_last_cte AS (
    SELECT 
        user_id, 
        DATE(call_time) AS day, 
        MIN(call_time)  AS min_time, 
        MAX(call_time)  AS max_time
    FROM call_cte
    GROUP BY 1, 2
    ORDER BY NULL
),
first_cte AS (
    SELECT a.user_id, DATE(call_time) AS call_date, recipient_id
    FROM call_cte a
    INNER JOIN first_last_cte b
    ON a.user_id = b.user_id
    AND a.call_time = b.min_time
),
last_cte AS (
    SELECT a.user_id, DATE(call_time) AS call_date, recipient_id
    FROM call_cte a
    INNER JOIN first_last_cte b
    ON a.user_id = b.user_id
    AND a.call_time = b.max_time
)

SELECT DISTINCT a.user_id
FROM first_cte a
INNER JOIN last_cte b
ON a.user_id = b.user_id
AND a.call_date = b.call_date
AND a.recipient_id = b.recipient_id;


# Time:  O(nlogn)
# Space: O(n)
WITH call_cte AS
(
    SELECT caller_id AS user_id, call_time, recipient_id
    FROM Calls
    UNION 
    SELECT recipient_id AS user_id, call_time, caller_id AS recipient_id
    FROM Calls
),
call_ordering_cte AS
(
    SELECT  user_id, recipient_id, DATE(call_time) AS day,
    RANK() OVER(PARTITION BY user_id, DATE(call_time) ORDER BY call_time ASC) AS first,
    RANK() OVER(PARTITION BY user_id, DATE(call_time) ORDER BY call_time DESC) AS last
    FROM call_cte
)

SELECT DISTINCT user_id
FROM call_ordering_cte
WHERE first = 1 OR last = 1
GROUP BY user_id, day
HAVING COUNT(DISTINCT recipient_id) = 1
ORDER BY NULL;

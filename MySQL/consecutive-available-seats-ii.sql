# Time:  O(nlogn)
# Space: O(n)

# window function
WITH window_cte AS (
    SELECT seat_id, free,
           ROW_NUMBER() OVER (ORDER BY seat_id DESC) as rnk
    FROM Cinema
    WHERE free = 1
), group_cte AS (
    SELECT seat_id, (rnk + seat_id) AS group_number
    FROM window_cte
), order_cte AS (
    SELECT MIN(seat_id) AS first_seat_id,
           MAX(seat_id) AS last_seat_id,
           COUNT(*) AS consecutive_seats_len
    FROM group_cte
    GROUP BY group_number
    ORDER BY NULL
)

SELECT *
FROM order_cte
WHERE consecutive_seats_len = (SELECT MAX(consecutive_seats_len) FROM order_cte)
ORDER BY 1;

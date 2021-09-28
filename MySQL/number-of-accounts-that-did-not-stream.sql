# Time:  O(m + n)
# Space: O(m + n)

WITH bought_cte AS
(
    SELECT account_id
    FROM Subscriptions
    WHERE end_date >= '2021-01-01'
),
no_stream_cte AS
(
    SELECT account_id
    FROM Streams
    WHERE stream_date < '2021-01-01'
)

SELECT COUNT(a.account_id) AS accounts_count
FROM bought_cte a
INNER JOIN no_stream_cte b
ON a.account_id = b.account_id;

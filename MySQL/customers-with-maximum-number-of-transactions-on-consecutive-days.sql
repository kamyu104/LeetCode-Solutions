# Time:  O(nlogn)
# Space: O(n)

WITH group_cte AS (
    SELECT customer_id, 
           (DATEDIFF(transaction_date, MIN(transaction_date) OVER (PARTITION BY customer_id)))+1
           - (ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY transaction_date)) AS diff
    FROM transactions
),
cnt_cte AS (
    SELECT customer_id, COUNT(*) AS cnt
    FROM group_cte
    GROUP BY customer_id, diff
    ORDER BY NULL
)

SELECT customer_id
FROM cnt_cte
WHERE cnt = (SELECT MAX(cnt) FROM cnt_cte) 
ORDER BY customer_id;

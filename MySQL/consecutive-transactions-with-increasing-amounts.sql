# Time:  O(nlogn)
# Space: O(n)

WITH date_group_cte AS (
    SELECT *, 
           TO_DAYS(transaction_date) - ROW_NUMBER() OVER (PARTITION BY customer_id 
                                                          ORDER BY transaction_date
           ) AS date_group
    FROM Transactions
), 
increasing_date_group_cte AS (
    SELECT  *, 
            (
                CASE WHEN amount <= LAG(amount, 1, amount) OVER (PARTITION BY customer_id, date_group 
                                                                 ORDER BY transaction_date
                ) THEN 1 ELSE 0 END
            ) start 
    FROM date_group_cte
),
group_cte AS (
    SELECT *,
           SUM(start) OVER (PARTITION BY customer_id ORDER BY transaction_date) AS group_id 
    FROM increasing_date_group_cte
)

SELECT customer_id,
       MIN(transaction_date) AS consecutive_start,
       MAX(transaction_date) AS consecutive_end
FROM group_cte
GROUP BY customer_id, group_id
HAVING COUNT(*) >= 3
ORDER BY customer_id;

# Time:  O(nlogn)
# Space: O(n)

WITH prev_cte AS (
    SELECT *,
           RANK () OVER (PARTITION BY user_id ORDER BY transaction_date) AS rnk,
           LAG(spend, 1) OVER (PARTITION BY user_id ORDER BY transaction_date) AS prev1,
           LAG(spend, 2) OVER (PARTITION BY user_id ORDER BY transaction_date) AS prev2
    FROM Transactions
)

SELECT user_id, spend AS third_transaction_spend, transaction_date AS third_transaction_date
FROM prev_cte
WHERE rnk = 3 AND prev2 < spend AND prev1 < spend
ORDER BY 1;

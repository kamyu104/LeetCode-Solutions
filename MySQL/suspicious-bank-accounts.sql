# Time:  O(nlogn)
# Space: O(n)

WITH transaction_cte AS
  (SELECT t.account_id,
          DATE_FORMAT(DAY, '%Y%m') AS month,
          SUM(amount) AS total_income,
          a.max_income
   FROM Transactions t
        LEFT JOIN Accounts a
               ON a.account_id = t.account_id
   WHERE t.type = 'Creditor'
   GROUP BY 1, 2
   HAVING total_income > a.max_income),
     consecutive_cte AS
  (SELECT account_id,
          LEAD(month, 1) OVER(PARTITION BY account_id
                              ORDER BY month) - month AS month_diff
   FROM transaction_cte)

SELECT DISTINCT account_id
FROM consecutive_cte
WHERE month_diff = 1;

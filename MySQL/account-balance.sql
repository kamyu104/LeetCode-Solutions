# Time:  O(nlogn)
# Space: O(n)

SELECT account_id, day,
       SUM(CASE WHEN type = 'DEPOSIT' THEN amount ELSE -amount END)
       OVER (PARTITION BY account_id ORDER BY day) AS balance
FROM Transactions;

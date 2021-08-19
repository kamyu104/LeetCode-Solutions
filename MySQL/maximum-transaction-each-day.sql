# Time:  O(nlogn)
# Space: O(n)

SELECT transaction_id
FROM (SELECT transaction_id, 
             RANK() OVER(PARTITION BY DATE(day) ORDER BY amount DESC) AS ranks
      FROM Transactions) tmp
WHERE ranks = 1
ORDER BY transaction_id;


# Time:  O(nlogn)
# Space: O(n)
SELECT transaction_id
FROM (SELECT DATE(day) as date_yyyymmdd, MAX(amount) as max_amount
      FROM Transactions
      GROUP BY DATE(day)) tmp
      INNER JOIN Transactions t
      ON date_yyyymmdd = DATE(t.day) AND max_amount = amount
ORDER BY transaction_id;

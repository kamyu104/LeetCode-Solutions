# Time:  O(n)
# Space: O(n)

SELECT month,
       country,
       SUM(IF(type = 'approved', 1, 0)) AS approved_count,
       SUM(IF(type = 'approved', amount, 0)) AS approved_amount,
       SUM(IF(type = 'chargeback', 1, 0)) AS chargeback_count,
       SUM(IF(type = 'chargeback', amount, 0)) AS chargeback_amount
FROM (
        (SELECT LEFT(t.trans_date, 7) AS month,
                t.country,
                amount,
                'approved' AS type
         FROM Transactions AS t
         WHERE state = 'approved' )
      UNION ALL
        (SELECT LEFT(c.trans_date, 7) AS month,
                t.country,
                amount,
                'chargeback' AS type
         FROM Transactions AS t
         INNER JOIN Chargebacks AS c ON t.id = c.trans_id)) AS tt
GROUP BY tt.month,
         tt.country;

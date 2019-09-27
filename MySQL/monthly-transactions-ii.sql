# Time:  O(n)
# Space: O(n)

SELECT MONTH,
       country,
       sum(IF(TYPE = "approved", 1, 0)) AS approved_count,
       sum(IF(TYPE = "approved", amount, 0)) AS approved_amount,
       sum(IF(TYPE = "chargeback", 1, 0)) AS chargeback_count,
       sum(IF(TYPE = "chargeback", amount, 0)) AS chargeback_amount
FROM (
        (SELECT left(t.trans_date, 7) AS MONTH,
                t.country,
                amount,
                'approved' AS TYPE
         FROM Transactions AS t
         WHERE state='approved' )
      UNION ALL
        (SELECT left(c.trans_date, 7) AS MONTH,
                t.country,
                amount,
                'chargeback' AS TYPE
         FROM Transactions AS t
         INNER JOIN Chargebacks AS c ON t.id = c.trans_id)) AS tt
GROUP BY tt.month,
         tt.country;

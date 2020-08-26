# Time:  O(m + n)
# Space: O(m + n)

SELECT user_id,
       user_name,
       (credit - IFNULL(out_cash, 0) + IFNULL(in_cash, 0)) AS credit,
       IF((credit - IFNULL(out_cash, 0) + IFNULL(in_cash, 0)) < 0, 'Yes', 'No') AS credit_limit_breached
FROM Users users
LEFT JOIN
  (SELECT paid_by,
          SUM(amount) AS out_cash
   FROM TRANSACTION
   GROUP BY paid_by
   ORDER BY NULL) out_tmp ON users.user_id = out_tmp.paid_by
LEFT JOIN
  (SELECT paid_to,
          SUM(amount) AS in_cash
   FROM TRANSACTION
   GROUP BY paid_to
   ORDER BY NULL) in_tmp ON users.user_id = in_tmp.paid_to;

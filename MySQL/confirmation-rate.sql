# Time:  O(n + m)
# Space: O(n + m)

WITH rate_cte AS
  (SELECT user_id,
          ROUND(SUM(CASE
                        WHEN action='confirmed' THEN 1
                        ELSE 0
                    END) / COUNT(*), 2) AS confirmation_rate
   FROM Confirmations
   GROUP BY user_id
   ORDER BY NULL)

SELECT s.user_id,
       IFNULL(r.confirmation_rate, 0) AS confirmation_rate
FROM Signups s
LEFT JOIN rate_cte r ON s.user_id = r.user_id;

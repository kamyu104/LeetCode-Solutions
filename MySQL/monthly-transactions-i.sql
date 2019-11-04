# Time:  O(n)
# Space: O(n)

SELECT Date_format(trans_date, '%Y-%m')       AS month, 
       country, 
       Count(id)                              AS trans_count, 
       Count(IF(state = 'approved', 1, NULL)) AS approved_count, 
       SUM(amount)                            AS trans_total_amount, 
       SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount 
FROM   transactions 
GROUP  BY Date_format(trans_date, '%Y-%m'), 
          country 
ORDER BY NULL

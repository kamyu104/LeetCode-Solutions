# Time:  O(n)
# Space: O(n)

SELECT extra                   AS report_reason, 
       Count(DISTINCT post_id) AS report_count 
FROM   actions 
WHERE  action = 'report' 
       AND action_date = '2019-07-04' 
GROUP  BY extra
ORDER  BY NULL

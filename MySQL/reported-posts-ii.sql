# Time:  O(m + n)
# Space: O(n)

SELECT ROUND(AVG(removal_percent), 2) average_daily_percent
FROM
  (SELECT a.action_date,
          COUNT(DISTINCT r.post_id) / COUNT(DISTINCT a.post_id) * 100 removal_percent
   FROM Actions a
   LEFT JOIN Removals r ON a.post_id = r.post_id
   WHERE a.extra = 'spam'
   GROUP BY a.action_date
   ORDER BY NULL) tmp

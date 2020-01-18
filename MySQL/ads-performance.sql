# Time:  O(nlogn)
# Space: O(n)

SELECT ad_id,
       CASE
           WHEN clicks + views = 0 THEN 0
           ELSE ROUND(100 * clicks / (clicks + views), 2)
       END ctr
FROM
  (SELECT ad_id,
          SUM(CASE
                  WHEN action ='Viewed' THEN 1
                  ELSE 0
              END) views,
          SUM(CASE
                  WHEN action = 'Clicked' THEN 1
                  ELSE 0
              END) clicks
   FROM Ads
   GROUP BY ad_id) a
ORDER BY ctr DESC,
         ad_id ASC
 

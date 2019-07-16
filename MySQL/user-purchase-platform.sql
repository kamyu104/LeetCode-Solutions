# Time:  O(n)
# Space: O(n)

SELECT t1.spend_date, 
       'both'                       AS platform, 
       Sum(Ifnull(t.sum_amount, 0)) AS total_amount, 
       Count(t.user_id)             AS total_users 
FROM   (SELECT spend_date, 
               user_id, 
               Sum(amount) AS sum_amount 
        FROM   spending 
        GROUP  BY spend_date, 
                  user_id 
        HAVING Count(platform) = 2) AS t 
       RIGHT JOIN (SELECT DISTINCT spend_date 
                   FROM   spending) AS t1
               ON t.spend_date = t1.spend_date 
GROUP  BY t1.spend_date 
UNION 
SELECT t2.spend_date, 
       'mobile'                 AS platform, 
       Sum(Ifnull(t.amount, 0)) AS total_amount, 
       Count(t.user_id)         AS total_users 
FROM   (SELECT spend_date, 
               user_id, 
               platform, 
               amount 
        FROM   spending 
        GROUP  BY spend_date, 
                  user_id 
        HAVING Count(platform) < 2) AS t 
       RIGHT JOIN (SELECT DISTINCT spend_date 
                   FROM   spending) AS t2 
               ON t.spend_date = t2.spend_date 
                  AND t.platform = 'mobile' 
GROUP  BY t2.spend_date 
UNION 
SELECT t3.spend_date, 
       'desktop'                AS platform, 
       Sum(Ifnull(t.amount, 0)) AS total_amount, 
       Count(t.user_id)         AS total_users 
FROM   (SELECT spend_date, 
               user_id, 
               platform, 
               amount 
        FROM   spending 
        GROUP  BY spend_date, 
                  user_id 
        HAVING Count(platform) < 2) AS t 
       RIGHT JOIN (SELECT DISTINCT spend_date 
                   FROM   spending) AS t3
               ON t.spend_date = t3.spend_date 
                  AND t.platform = 'desktop' 
GROUP  BY t3.spend_date

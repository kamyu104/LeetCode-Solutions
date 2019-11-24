# Time:  O(m + n)
# Space: O(m)

SELECT DISTINCT page_id AS recommended_page 
FROM   likes l2 
WHERE  NOT EXISTS (SELECT *
                   FROM   likes l1 
                   WHERE  l1.user_id = 1 
                          AND l1.page_id = l2.page_id) 
       AND user_id IN (SELECT user2_id AS friend_id 
                       FROM   friendship 
                       WHERE  user1_id = 1 
                       UNION 
                       SELECT user1_id AS friend_id 
                       FROM   friendship 
                       WHERE  user2_id = 1) 

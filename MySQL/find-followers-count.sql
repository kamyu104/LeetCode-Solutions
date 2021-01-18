# Time:  O(nlogn)
# Space: O(n)

SELECT user_id, 
       Count(follower_id) AS followers_count 
FROM   followers 
GROUP  BY user_id 
ORDER  BY user_id; 

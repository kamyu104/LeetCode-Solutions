# Time:  O(n)
# Space: O(n)

SELECT * 
FROM   users AS u 
WHERE  u.mail REGEXP '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode.com$'; 

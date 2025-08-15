# Time:  O(n)
# Space: O(n)

SELECT * 
FROM   users AS u 
WHERE REGEXP_LIKE(u.mail, '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$', 'c');

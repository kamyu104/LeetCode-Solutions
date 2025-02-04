# Time:  O(n)
# Space: O(n)

# regular expression
SELECT user_id, email 
FROM users
WHERE email REGEXP '^[a-zA-Z0-9_]+@[a-zA-Z]+\.com$'
ORDER BY 1;

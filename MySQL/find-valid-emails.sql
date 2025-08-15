# Time:  O(n)
# Space: O(n)

# regular expression
SELECT user_id, email 
FROM users
WHERE REGEXP_LIKE(email, '^[a-zA-Z0-9_]+@[a-zA-Z]+\\.com$', 'c')
ORDER BY 1;

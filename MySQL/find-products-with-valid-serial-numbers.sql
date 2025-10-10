# Time:  O(n)
# Space: O(1)

# regular expression
SELECT *
FROM products
WHERE description REGEXP '(?-i)\\bSN[0-9]{4}-[0-9]{4}\\b'
ORDER BY product_id

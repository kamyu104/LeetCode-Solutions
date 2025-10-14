# Time:  O(nlogn)
# Space: O(n)

# regular expression
SELECT product_id, product_name, description
FROM products
WHERE REGEXP_LIKE(description, '\\bSN[0-9]{4}-[0-9]{4}\\b', 'c')
ORDER BY 1;

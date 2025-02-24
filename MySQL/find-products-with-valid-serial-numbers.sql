# Time:  O(nlogn)
# Space: O(n)

# regular expression
SELECT product_id, product_name, description
FROM products
WHERE description REGEXP "SN[0-9]{4}-[0-9]{4}[^0-9]*$"
ORDER BY 1;

# Time:  O(n)
# Space: O(n)

SELECT customer_id
FROM customers
WHERE YEAR = 2021 AND revenue > 0;

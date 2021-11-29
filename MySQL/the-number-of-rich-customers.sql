# Time:  O(n)
# Space: O(n)

SELECT COUNT(DISTINCT customer_id) AS rich_count
FROM Store
WHERE amount > 500;

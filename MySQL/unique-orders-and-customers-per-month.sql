# Time:  O(n)
# Space: O(n)

SELECT LEFT(order_date, 7) month,
       COUNT(DISTINCT order_id) order_count,
       COUNT(DISTINCT customer_id) customer_count
FROM orders
WHERE invoice > 20
GROUP BY 1
ORDER BY NULL;

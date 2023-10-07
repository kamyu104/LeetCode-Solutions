# Time:  O(nlogn)
# Space: O(n)

SELECT CEIL(minute / 6) AS interval_no, SUM(order_count) AS total_orders
FROM Orders
GROUP BY 1
ORDER BY 1;

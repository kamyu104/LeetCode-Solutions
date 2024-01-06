# Time:  O(n)
# Space: O(n)

SELECT ROUND(SUM(item_count * order_occurrences) / SUM(order_occurrences), 2) AS average_items_per_order
FROM Orders;

# Time:  O(nlogn)
# Space: O(n)

SELECT customer_id,
       COUNT(*) AS total_orders,
       ROUND(SUM(IF((HOUR(order_timestamp) BETWEEN 11 AND 13) OR (HOUR(order_timestamp) BETWEEN 18 AND 20), 1, 0)) / COUNT(*), 2) * 100 AS peak_hour_percentage,
       ROUND(AVG(order_rating), 2) AS average_rating
FROM restaurant_orders
GROUP BY customer_id
HAVING total_orders >= 3
   AND peak_hour_percentage >= 60.0
   AND average_rating >= 4.0
   AND SUM(IF(order_rating IS NOT NULL, 1, 0)) * 2 > total_orders
ORDER BY 4 DESC, 1 DESC;

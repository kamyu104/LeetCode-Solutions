# Time:  O(nlogn)
# Space: O(n)

SELECT s.user_id,
       SUM(s.quantity * p.price) AS spending
FROM Sales s INNER JOIN Product p ON s.product_id = p.product_id
GROUP BY s.user_id
ORDER BY spending DESC, s.user_id ASC;

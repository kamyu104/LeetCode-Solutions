# Time:  O(n)
# Space: O(n)

SELECT * FROM Orders
WHERE (customer_id, order_type) 
IN (SELECT customer_id, MIN(order_type) 
    FROM Orders 
    GROUP BY customer_id
    ORDER BY NULL);


# Time:  O(nlogn)
# Space: O(n)
WITH cte AS(
SELECT *, RANK() OVER(PARTITION BY customer_id ORDER BY order_type) AS rnk
FROM Orders
)
SELECT order_id, customer_id, order_type
FROM cte
WHERE rnk = 1;

# Time:  O(n)
# Space: O(n)

SELECT name AS warehouse_name,
       SUM(units*Width*LENGTH*Height) AS volume
FROM Warehouse w
INNER JOIN Products p ON w.product_id = p.product_id
GROUP BY name
ORDER BY NULL;

# Time:  O(n)
# Space: O(n)

SELECT name AS warehouse_name,
       SUM(units*Width*LENGTH*Height) AS volume
FROM Warehouse
INNER JOIN Products ON Warehouse.product_id = Products.product_id
GROUP BY name
ORDER BY NULL;

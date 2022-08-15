# Time:  O(sp + c + s)
# Space: O(sp + c + s)

SELECT sp.salesperson_id, sp.name, SUM(IFNULL(price, 0)) AS total
FROM Salesperson sp
LEFT JOIN Customer c ON sp.salesperson_id = c.salesperson_id
LEFT JOIN Sales s ON c.customer_id = s.customer_id
GROUP BY sp.salesperson_id, sp.name
ORDER BY NULL;

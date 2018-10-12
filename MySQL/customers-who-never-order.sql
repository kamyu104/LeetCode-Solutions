# Time:  O(n^2)
# Space: O(1)

SELECT Name AS Customers FROM Customers WHERE Id NOT IN (SELECT CustomerId FROM Orders)

SELECT Customers.Name AS Customers FROM (Customers LEFT JOIN Orders ON Customers.Id = Orders.CustomerId) WHERE Orders.CustomerId IS NULL


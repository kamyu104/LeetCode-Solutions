# Time: O(n^2)
# Space: O(1)

SELECT e.Name AS Employee  FROM Employee e LEFT JOIN Employee b
       ON e.ManagerId=b.Id
       WHERE e.Salary > b.Salary

SELECT Name AS Employee 
    FROM Employee e 
    WHERE e.ManagerId IS NOT NULL AND e.Salary > (SELECT Salary 
                          FROM Employee 
                          WHERE e.ManagerId = Id)


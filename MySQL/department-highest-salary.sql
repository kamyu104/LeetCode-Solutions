# Time:  O(n^2)
# Space: O(n)

SELECT d.Department AS Department, e.Name AS Employee, d.Salary AS Salary
FROM (SELECT Department.Id AS DepartmentId, Department.Name AS Department, emp.Salary AS Salary
        FROM Department JOIN (SELECT DepartmentId, MAX(Salary) AS Salary FROM Employee GROUP BY DepartmentId) emp
        ON Department.Id = emp.DepartmentId) d 
      JOIN Employee e 
      ON e.DepartmentId = d.DepartmentId and e.Salary = d.Salary

SELECT Department.Name AS Department, Employee.Name AS Employee, Employee.Salary AS Salary
FROM Department JOIN Employee ON Employee.DepartmentId = Department.Id
WHERE Employee.Salary IN (SELECT MAX(e.Salary) FROM Employee e WHERE e.DepartmentId = Employee.DepartmentId)


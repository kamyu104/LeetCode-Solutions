# Time:  O(nlogn)
# Space: O(n)

WITH teams_cte AS
  (SELECT salary,
          DENSE_RANK() OVER (ORDER BY salary) AS team_id
   FROM Employees
   GROUP BY salary
   HAVING COUNT(salary) > 1)

SELECT e.employee_id AS employee_id,
       e.name AS name,
       t.salary AS salary,
       t.team_id AS team_id
FROM teams_cte AS t
INNER JOIN Employees AS e ON t.salary = e.salary
ORDER BY t.team_id,
         e.employee_id;

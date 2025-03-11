# Time:  O(n^2)
# Space: O(n^2)

# recursive cte, bfs
WITH RECURSIVE level_cte AS (
    SELECT employee_id, manager_id, 1 AS level, salary 
    FROM Employees
    UNION ALL
    SELECT a.employee_id, b.manager_id, level + 1, a.salary
    FROM level_cte a
    INNER JOIN Employees b ON b.employee_id = a.manager_id
),
employee_with_level_cte AS (
    SELECT a.employee_id, a.employee_name, a.salary, b.level 
    FROM Employees a
    INNER JOIN (
        SELECT employee_id, level 
        FROM level_cte  
        WHERE manager_id IS NULL
    ) b 
    ON a.employee_id = b.employee_id
)

SELECT a.employee_id, 
       a.employee_name, 
       a.level, 
       IFNULL(b.team_size, 0) AS team_size,
       a.salary + IFNULL(b.budget, 0) AS budget
FROM employee_with_level_cte a
LEFT JOIN (
    SELECT manager_id AS employee_id, 
           COUNT(*) AS team_size, 
           SUM(salary) AS budget 
    FROM level_cte 
    WHERE manager_id IS NOT NULL 
    GROUP BY 1
    ORDER BY NULL
) b ON a.employee_id = b.employee_id
ORDER BY 3, 5 DESC, 2;

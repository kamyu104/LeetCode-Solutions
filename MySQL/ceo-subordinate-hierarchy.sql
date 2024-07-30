# Time:  O(nlogn)
# Space: O(n)

# recursive cte, bfs
WITH RECURSIVE cte AS (
    SELECT employee_id AS subordinate_id,
           employee_name AS subordinate_name,
           0 AS hierarchy_level,
           salary
    FROM Employees
    WHERE manager_id IS NULL
    UNION ALL
    SELECT e.employee_id AS subordinate_id,
           e.employee_name AS subordinate_name,
           hierarchy_level + 1,
           e.salary
    FROM Employees AS e INNER JOIN cte ON e.manager_id = cte.subordinate_id
)

SELECT subordinate_id,
       subordinate_name,
       hierarchy_level,
       salary - (SELECT salary FROM Employees WHERE manager_id IS NULL) AS salary_difference
FROM cte
WHERE hierarchy_level > 0
ORDER BY 3, 1;

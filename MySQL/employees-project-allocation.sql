# Time:  O(nlogn)
# Space: O(n)

WITH workload_cte AS (
    SELECT e.employee_id,
           p.project_id,
           e.name AS employee_name,
           p.workload AS project_workload,
           AVG(p.workload) OVER(PARTITION BY e.team ORDER BY NULL) AS average_team_workload
    FROM Employees e
    LEFT JOIN Project p
    ON e.employee_id = p.employee_id
)

SELECT employee_id, project_id, employee_name, project_workload
FROM workload_cte
WHERE project_workload > average_team_workload
ORDER BY 1, 2;

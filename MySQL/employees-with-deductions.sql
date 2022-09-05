# Time:  O(n)
# Space: O(n)

SELECT e.employee_id
FROM Employees e 
LEFT JOIN Logs l ON e.employee_id = l.employee_id
GROUP BY e.employee_id
HAVING COALESCE(SUM(CEIL(TIMESTAMPDIFF(SECOND, l.in_time, l.out_time) / 60) / 60), 0) < MAX(e.needed_hours)
ORDER BY NULL;

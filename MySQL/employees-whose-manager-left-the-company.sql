# Time:  O(nlogn)
# Space: O(n)

SELECT employee_id
FROM Employees a
WHERE salary < 30000 
      AND manager_id IS NOT NULL
      AND NOT EXISTS (SELECT 1 
                      FROM Employees b
                      WHERE b.employee_id = a.manager_id)
ORDER BY employee_id;

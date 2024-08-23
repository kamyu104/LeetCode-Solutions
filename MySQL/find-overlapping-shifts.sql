# Time:  O(n^2)
# Space: O(n^2)

WITH cte AS (
    SELECT e1.employee_id
    FROM EmployeeShifts e1
    INNER JOIN EmployeeShifts e2
        ON e1.employee_id = e2.employee_id
    WHERE e1.start_time < e2.start_time
      AND e1.end_time > e2.start_time
)

SELECT employee_id,
       COUNT(*) AS overlapping_shifts
FROM cte
GROUP BY 1
ORDER BY 1;

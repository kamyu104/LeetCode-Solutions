# Time:  O(nlogn)
# Space: O(n)

WITH all_employee_info_cte AS
(
    SELECT employee_id FROM Employees
    UNION ALL
    SELECT employee_id FROM Salaries
)

SELECT employee_id
FROM all_employee_info_cte
GROUP BY employee_id
HAVING COUNT(*) != 2
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)
WITH all_employee_id_cte AS
(
    SELECT employee_id FROM Employees
    UNION
    SELECT employee_id FROM Salaries
),
complete_employee_id_cte AS
(
    SELECT a.employee_id 
    FROM Employees a
    INNER JOIN Salaries b
    ON a.employee_id = b.employee_id
)

SELECT employee_id
FROM all_employee_id_cte a
WHERE NOT EXISTS (SELECT 1 FROM complete_employee_id_cte b WHERE a.employee_id = b.employee_id)
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)
WITH all_employee_info_cte AS
(
    (
        SELECT a.employee_id, a.name, b.salary
        FROM Employees a
        LEFT JOIN Salaries b 
        ON a.employee_id = b.employee_id
    )
    UNION
    (
        SELECT b.employee_id, a.name, b.salary
        FROM Employees a
        RIGHT JOIN Salaries b 
        ON a.employee_id = b.employee_id
    )
)

SELECT employee_id
FROM all_employee_info_cte tmp
WHERE name IS NULL OR salary IS NULL
ORDER BY 1;

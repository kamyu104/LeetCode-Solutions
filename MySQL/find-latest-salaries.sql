# Time:  O(nlogn)
# Space: O(n)

SELECT DISTINCT 
    emp_id,
    firstname,
    lastname,
    MAX(salary) AS salary,
    department_id   
FROM Salary
GROUP BY emp_id
ORDER BY emp_id ASC;

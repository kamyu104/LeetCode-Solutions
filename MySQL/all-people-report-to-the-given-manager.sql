# Time:  O(n)
# Space: O(n)

SELECT e1.employee_id 
FROM   employees e1 
       LEFT JOIN employees e2 
              ON e1.manager_id = e2.employee_id 
       LEFT JOIN employees e3 
              ON e2.manager_id = e3.employee_id 
WHERE  e3.manager_id = 1 
       AND e1.employee_id != 1 

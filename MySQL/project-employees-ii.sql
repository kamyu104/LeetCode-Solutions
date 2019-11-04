# Time:  O(n)
# Space: O(n)

SELECT project_id 
FROM   project 
GROUP  BY project_id 
HAVING Count(employee_id) = (SELECT Count(employee_id) 
                             FROM   project 
                             GROUP  BY project_id 
                             ORDER  BY Count(employee_id) DESC 
                             LIMIT  1) 
ORDER  BY NULL 

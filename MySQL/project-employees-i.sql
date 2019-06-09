# Time:  O(m + n) 
# Space: O(m + n) 

SELECT project_id, 
       Round(Avg(experience_years), 2) AS average_years 
FROM   project AS p 
       INNER JOIN employee AS e 
               ON p.employee_id = e.employee_id 
GROUP  BY project_id 
ORDER  BY NULL 

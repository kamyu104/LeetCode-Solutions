# Time:  O(nlogn)
# Space: O(n)

SELECT e1.employee_id, 
       e1.NAME, 
       Count(e2.reports_to)  AS reports_count, 
       Round(Avg(e2.age), 0) AS average_age 
FROM   employees e1 
       INNER JOIN employees e2 
               ON e1.employee_id = e2.reports_to 
GROUP  BY e1.employee_id, 
          e1.NAME 
ORDER  BY 1 ASC; 

# Time:  O(m + n)
# Space: O(m + n)

SELECT s.company_id,
       s.employee_id,
       s.employee_name,
       ROUND(s.salary * t.rate) salary
FROM Salaries s
INNER JOIN
  (SELECT company_id,
          CASE
              WHEN MAX(salary) < 1000 THEN 1.0
              WHEN MAX(salary) <= 10000 THEN 0.76
              ELSE 0.51
          END AS rate
   FROM Salaries
   GROUP BY company_id
   ORDER BY NULL) t ON s.company_id = t.company_id;
 

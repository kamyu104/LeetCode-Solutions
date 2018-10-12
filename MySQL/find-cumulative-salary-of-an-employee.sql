# Time:  O(n^2)
# Space: O(n)

SELECT EA.Id, 
       EA.Month, 
       SUM(EB.salary) AS Salary 
FROM   (SELECT E1.* 
        FROM   employee E1 
               LEFT JOIN (SELECT id, 
                                 MAX(month) AS month 
                          FROM   employee 
                          GROUP  BY id) E2 
                      ON E1.id = E2.id 
        WHERE  E1.month < E2.month) EA 
       LEFT JOIN employee EB 
              ON EA.id = EB.id 
WHERE  EA.month - 2 <= EB.month
       AND EB.month <= EA.month
GROUP  BY EA.id, 
          EA.month 
ORDER  BY EA.id, 
          month DESC 


# Time:  O((m + n)^2)
# Space: O(m + n)

SELECT project_id, 
       p1.employee_id 
FROM   project AS p1 
       INNER JOIN employee AS e1 
               ON p1.employee_id = e1.employee_id 
WHERE  ( project_id, experience_years ) IN (SELECT project_id, 
                                                   Max(experience_years) 
                                            FROM   project AS p2 
                                                   INNER JOIN employee AS e2 
                                                           ON p2.employee_id = 
                                                              e2.employee_id 
                                            GROUP  BY project_id 
                                            ORDER  BY NULL) 

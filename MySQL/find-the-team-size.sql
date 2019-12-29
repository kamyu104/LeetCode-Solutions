# Time:  O(n)
# Space: O(n)

SELECT employee_id, 
       team_size 
FROM   employee AS e 
       LEFT JOIN (SELECT team_id, 
                         Count(1) AS team_size 
                  FROM   employee 
                  GROUP  BY team_id) AS teams 
              ON e.team_id = teams.team_id 

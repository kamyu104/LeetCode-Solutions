# Time:  O(n) 
# Space: O(n) 
SELECT s.id, 
       s.name 
FROM   students s 
       LEFT JOIN departments d 
              ON d.id = s.department_id 
WHERE  d.id IS NULL; 

# Time:  O(n) 
# Space: O(n) 
SELECT s.id, 
       s.name 
FROM   students s
WHERE  NOT EXISTS (SELECT id 
                   FROM   departments d
                   WHERE  d.id = s.department_id); 

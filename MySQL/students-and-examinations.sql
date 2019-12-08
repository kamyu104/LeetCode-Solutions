# Time:  O((m * n) * log(m * n))
# Space: O(m * n)

SELECT a.student_id, 
       a.student_name, 
       b.subject_name, 
       Count(c.subject_name) AS attended_exams 
FROM   students AS a 
       CROSS JOIN subjects AS b 
       LEFT JOIN examinations AS c 
              ON a.student_id = c.student_id 
                 AND b.subject_name = c.subject_name 
GROUP  BY a.student_id, 
          b.subject_name
ORDER  BY a.student_id, 
          b.subject_name;

# Time:  O(nlogn)
# Space: O(n)

SELECT student_id, 
       Min(course_id) AS course_id, 
       grade 
FROM   enrollments 
WHERE  ( student_id, grade ) IN (SELECT student_id, 
                                        Max(grade) 
                                 FROM   enrollments 
                                 GROUP  BY student_id 
                                 ORDER  BY NULL) 
GROUP  BY student_id 
ORDER  BY student_id 

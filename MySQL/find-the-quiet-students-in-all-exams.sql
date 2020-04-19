# Time:  O(m + nlogn)
# Space: O(m + n)

SELECT s.student_id, 
       s.student_name 
FROM   student s 
       INNER JOIN (SELECT a.student_id, 
                          Count(a.exam_id) AS total_exam, 
                          Sum(CASE 
                                WHEN a.score > min_score 
                                     AND a.score < max_score THEN 1 
                                ELSE 0 
                              END)         AS quite_exam 
                   FROM   exam a 
                          INNER JOIN (SELECT exam_id, 
                                             Min(score) AS min_score, 
                                             Max(score) AS max_score 
                                      FROM   exam 
                                      GROUP  BY exam_id 
                                      ORDER  BY NULL) b 
                                  ON a.exam_id = b.exam_id 
                   GROUP  BY a.student_id 
                   ORDER  BY NULL) c 
               ON s.student_id = c.student_id 
WHERE  c.total_exam = c.quite_exam 
ORDER  BY s.student_id; 

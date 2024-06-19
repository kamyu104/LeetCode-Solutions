# Time:  O(nlogn)
# Space: O(n)

WITH best_enrollments_cte AS (
    SELECT student_id, course_id, MIN(grade) AS grade
    FROM enrollments
    GROUP BY 1, 2
    ORDER BY NULL
), major_mandatory_grade_a_count_cte AS (
    SELECT s.student_id, s.major, COUNT(*) AS cnt
    FROM best_enrollments_cte e INNER JOIN students s ON e.student_id = s.student_id INNER JOIN courses c ON e.course_id = c.course_id
    WHERE s.major = c.major AND mandatory = 'yes' and e.grade = 'A'
    GROUP BY 1
    ORDER BY NULL
), major_mandatory_count_cte AS (
    SELECT major, COUNT(*) AS cnt
    FROM courses
    WHERE mandatory = 'yes'
    GROUP BY 1
    ORDER BY NULL
), major_elective_grade_a_or_b_count_cte AS (
    SELECT s.student_id, s.major, COUNT(*) AS cnt
    FROM best_enrollments_cte e INNER JOIN students s ON e.student_id = s.student_id INNER JOIN courses c ON e.course_id = c.course_id
    WHERE s.major = c.major AND c.mandatory = 'no' and e.grade <= 'B'
    GROUP BY 1
    ORDER BY NULL
), gpa_cte AS (
    SELECT e.student_id, AVG(e.gpa) AS gpa
    FROM enrollments e
    GROUP BY 1
    ORDER BY NULL
)

SELECT c1.student_id
FROM major_mandatory_grade_a_count_cte c1
     INNER JOIN major_mandatory_count_cte c2 ON c1.major = c2.major
     INNER JOIN major_elective_grade_a_or_b_count_cte c3 ON c1.student_id = c3.student_id
     INNER JOIN gpa_cte c4 ON c1.student_id = c4.student_id
WHERE c1.cnt = c2.cnt AND c3.cnt >= 2 AND c4.gpa >= 2.5
ORDER BY 1;

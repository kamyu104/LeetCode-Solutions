# Time:  O(nlogn)
# Space: O(n)

WITH major_grade_a_count_cte AS (
    SELECT s.student_id, s.major,  COUNT(*) AS cnt
    FROM enrollments e INNER JOIN students s ON e.student_id = s.student_id INNER JOIN courses c ON e.course_id = c.course_id
    WHERE s.major = c.major AND e.grade = 'A'
    GROUP BY 1
    ORDER BY NULL
), major_count_cte AS (
    SELECT major, COUNT(*) AS cnt
    FROM courses
    GROUP BY 1
    ORDER BY NULL
)

SELECT c1.student_id
FROM major_grade_a_count_cte c1 INNER JOIN major_count_cte c2 ON c1.major = c2.major
WHERE c1.cnt = c2.cnt
ORDER BY 1;

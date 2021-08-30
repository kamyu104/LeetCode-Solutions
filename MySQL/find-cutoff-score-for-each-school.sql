# Time:  O(n * m)
# Space: O(n * m)

SELECT school_id, IFNULL(min(score), -1) as score
FROM Schools LEFT JOIN Exam ON capacity >= student_count
GROUP BY school_id
ORDER BY NULL;

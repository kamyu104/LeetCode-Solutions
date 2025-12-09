# Time:  O(nlogn)
# Space: O(n)

# window function
WITH top_students_cte AS (
    SELECT user_id
    FROM course_completions
    GROUP BY 1
    HAVING COUNT(course_id) >= 5 
       AND AVG(course_rating) >= 4
    ORDER BY NULL
),
transitions_cte AS (
    SELECT c.user_id,
           course_name AS first_course,
           LEAD(course_name) OVER (PARTITION BY user_id ORDER BY completion_date ASC) AS second_course
    FROM course_completions c INNER JOIN top_students_cte t ON c.user_id = t.user_id
)

SELECT first_course,
       second_course,
       COUNT(*) AS transition_count
FROM transitions_cte
WHERE second_course IS NOT NULL
GROUP BY 1, 2
ORDER BY 3 DESC, 1 ASC, 2 ASC;

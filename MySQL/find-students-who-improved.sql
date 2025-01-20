# Time:  O(nlogn)
# Space: O(n)

# window function
WITH score_cte AS (
    SELECT student_id,
           subject,
           FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date) AS first_score,
           FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date DESC) AS latest_score
    FROM Scores
)

SELECT student_id,
       subject,
       first_score,
       latest_score 
FROM score_cte
WHERE first_score < latest_score
GROUP BY 1, 2
ORDER BY 1, 2;

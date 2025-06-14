# Time:  O(nlogn)
# Space: O(n)

# window function
WITH rank_cte AS (
    SELECT employee_id, 
           rating, 
           review_date, 
           ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rnk
    FROM performance_reviews
), 
top3_cte AS ( 
    SELECT employee_id, 
           MAX(CASE WHEN rnk = 3 THEN rating END) AS i, 
           MAX(CASE WHEN rnk = 2 THEN rating END) AS j, 
           MAX(CASE WHEN rnk = 1 THEN rating END) AS k
    FROM rank_cte
    WHERE rnk <= 3 
    GROUP BY 1
    ORDER BY NULL
), 
improvement_cte AS (
    SELECT employee_id, 
           k - i AS improvement_score
    FROM top3_cte
    WHERE i < j AND j < k
)

SELECT i.employee_id, 
       e.name, 
       i.improvement_score 
FROM improvement_cte AS i
LEFT JOIN employees AS e ON i.employee_id = e.employee_id
ORDER BY 3 DESC, 2;

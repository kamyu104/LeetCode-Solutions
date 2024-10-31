# Time:  O(nlogn)
# Space: O(n)

# window function
WITH emp_salary_rank_cte AS (
    SELECT emp_id,
           dept,
           DENSE_RANK() OVER (PARTITION BY dept ORDER BY salary DESC) AS dept_salary_rank
    FROM employees
)
  
SELECT emp_id,
       dept
FROM  emp_salary_rank_cte
WHERE dept_salary_rank = 2
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)

WITH manager_cte AS (
    SELECT emp_name AS manager_name, dep_id
    FROM employees
    WHERE position = 'Manager'
), dep_rank_cte AS (
    SELECT dep_id,
           COUNT(*) AS cnt,
           DENSE_RANK() OVER(ORDER BY count(*) DESC) AS rnk
    FROM employees
    GROUP BY 1
    ORDER BY NULL
)

SELECT manager_name, a.dep_id
FROM manager_cte a
INNER JOIN dep_rank_cte b ON a.dep_id = b.dep_id
WHERE rnk = 1
ORDER BY 2;

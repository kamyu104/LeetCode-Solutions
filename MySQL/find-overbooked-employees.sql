# Time:  O(m + nlogn)
# Space: O(m + n)

WITH overbooked_employees_cte AS (
    SELECT employee_id
    FROM meetings
    GROUP BY employee_id, YEAR(meeting_date), WEEKOFYEAR(meeting_date)
    HAVING SUM(duration_hours) > 20
    ORDER BY NULL
)

SELECT e.employee_id,
       e.employee_name,
       e.department,
       COUNT(*) AS meeting_heavy_weeks
FROM overbooked_employees_cte AS o
INNER JOIN employees AS e ON o.employee_id = e.employee_id
GROUP BY 1, 2, 3
HAVING meeting_heavy_weeks >= 2
ORDER BY 4 DESC, 2;

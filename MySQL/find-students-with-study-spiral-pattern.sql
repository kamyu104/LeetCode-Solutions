# Time:  O(nlogn)
# Space: O(n)

# window function
WITH gaps_cte AS (
  SELECT student_id,
         subject,
         session_date,
         hours_studied,
         DATEDIFF(session_date, LAG(session_date) OVER (PARTITION BY student_id ORDER BY session_date)) AS gap
  FROM study_sessions
),
groups_cte AS (
  SELECT student_id,
         subject,
         session_date,
         hours_studied,
         SUM(CASE WHEN gap IS NULL OR gap > 2 THEN 1 ELSE 0 END) OVER (PARTITION BY student_id ORDER BY session_date) AS group_id
  FROM gaps_cte
),
patterns_cte AS (
  SELECT g.student_id,
         g.group_id,
         GROUP_CONCAT(g.subject ORDER BY g.session_date SEPARATOR ',') AS seq,
         COUNT(*) AS total_sessions,
         COUNT(DISTINCT g.subject) AS cycle_length,
         ROUND(SUM(g.hours_studied), 1) AS total_study_hours
  FROM groups_cte g
  GROUP BY 1, 2
  HAVING total_sessions >= 6 
     AND cycle_length >= 3
     AND total_sessions % cycle_length = 0
     AND REPEAT(CONCAT(SUBSTRING_INDEX(seq, ',', cycle_length), ','), total_sessions / cycle_length) = CONCAT(seq, ',')
  ORDER BY NULL
)

SELECT p.student_id,
       s.student_name,
       s.major,
       p.cycle_length,
       p.total_study_hours
FROM patterns_cte p
INNER JOIN students s ON p.student_id = s.student_id
ORDER BY 4 DESC, 5 DESC;

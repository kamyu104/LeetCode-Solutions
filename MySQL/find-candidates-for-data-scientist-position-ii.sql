# Time:  O(p * s * n + p * nlogn + plogp)
# Space: O(p * s * n)

# window function
WITH counts_cte AS (
    SELECT project_id,
           COUNT(*) AS cnt
    FROM projects
    GROUP BY 1
    ORDER BY NULL
), scores_cte AS (
    SELECT a.project_id,
           b.candidate_id,
           COUNT(*) AS cnt,
           100 + SUM(IF(a.importance < b.proficiency, 10, IF(a.importance > b.proficiency, -5, 0))) AS score
    FROM projects a
    INNER JOIN candidates b ON a.skill = b.skill
    GROUP BY 1, 2
    ORDER BY NULL
), ranks_cte AS (
    SELECT a.project_id,
           a.candidate_id,
           a.score,
           ROW_NUMBER() OVER (PARTITION BY a.project_id ORDER BY a.score DESC, a.candidate_id) AS rnk
    FROM scores_cte a
    INNER JOIN counts_cte b ON a.project_id = b.project_id AND a.cnt = b.cnt
)

SELECT project_id,
       candidate_id,
       score
FROM ranks_cte
WHERE rnk = 1
ORDER BY 1;

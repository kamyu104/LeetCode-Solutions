# Time:  O(nlogn)
# Space: O(n)

# window function
WITH teams_points_cte AS (
    SELECT team_id,
           team_name,
           wins * 3 + draws * 1 + losses * 0 AS points
    FROM TeamStats
)

SELECT team_id,
       team_name,
       points,
       RANK() OVER (ORDER BY points DESC) AS position
FROM teams_points_cte
ORDER BY 4, 2;

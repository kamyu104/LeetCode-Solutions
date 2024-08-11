# Time:  O(nlogn)
# Space: O(n)

# window function
WITH teams_points_cte AS (
    SELECT team_id,
           team_name,
           wins * 3 + draws * 1 + losses * 0 AS points
    FROM TeamStats
), teams_ranks_cte AS (
    SELECT team_id,
        team_name,
        points,
        RANK() OVER (ORDER BY points DESC) AS position
    FROM teams_points_cte
), team_count_cte as  (
    SELECT COUNT(*) as num_teams
    FROM TeamStats
)

SELECT team_name,
       points,
       position,
       CASE WHEN position <= CEIL(num_teams * 0.33) THEN "Tier 1"
            WHEN position <= CEIL(num_teams * 0.66) THEN "Tier 2"
            ELSE "Tier 3"
       END AS tier
FROM teams_ranks_cte, team_count_cte
ORDER BY 2 DESC, 1;

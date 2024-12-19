# Time:  O(plogp + t)
# Space: O(p + t)

# recursive cte, window function
WITH RECURSIVE edges_cte AS (
    SELECT  t1.team_name AS team1, 
            t2.team_name AS team2, 
            time_stamp
    FROM Passes p
    INNER JOIN Teams t1 ON p.pass_from = t1.player_id
    INNER JOIN Teams t2 ON p.pass_to = t2.player_id    
),
sorted_edges_cte AS (
    SELECT team1, 
           team2, 
           RANK() OVER (PARTITION BY team1 ORDER BY time_stamp) AS rnk 
    FROM edges_cte
),
scores_cte AS (
    SELECT team1, 
           team2, 
           rnk, 
           IF(team1 = team2, 1, 0) AS score 
    FROM sorted_edges_cte
    WHERE rnk = 1
    UNION
    SELECT sorted_edges_cte.team1, 
           sorted_edges_cte.team2, 
           sorted_edges_cte.rnk, 
           IF(sorted_edges_cte.team1 = sorted_edges_cte.team2, scores_cte.score + 1, 0) AS score 
    FROM sorted_edges_cte
    INNER JOIN scores_cte ON sorted_edges_cte.rnk = scores_cte.rnk + 1 AND sorted_edges_cte.team1 = scores_cte.team1
)

SELECT team1 AS team_name, 
       MAX(score) AS longest_streak 
FROM scores_cte
GROUP BY 1 
HAVING longest_streak > 0 
ORDER BY 1;

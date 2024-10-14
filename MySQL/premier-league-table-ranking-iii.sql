# Time:  O(nlogn)
# Space: O(n)

# window function
SELECT  season_id,
        team_id, 
        team_name,
        wins * 3 + draws * 1 + losses * 0 AS points,
        goals_for - goals_against AS goal_difference,
        ROW_NUMBER() OVER (PARTITION BY season_id ORDER BY wins * 3 + draws * 1 + losses * 0 DESC, goals_for - goals_against DESC, team_name) AS position
FROM SeasonStats
ORDER BY 1, 6, 3;

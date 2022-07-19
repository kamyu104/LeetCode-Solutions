# Time:  O(n^2)
# Space: O(n^2)

SELECT a.team_name home_team,
       b.team_name away_team
FROM Teams a CROSS JOIN Teams b
ON a.team_name != b.team_name;

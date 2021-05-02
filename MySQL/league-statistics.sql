# Time:  O(nlogn)
# Space: O(n)

WITH match_score_cte AS
    (SELECT *,
          CASE
              WHEN home_team_goals > away_team_goals THEN 3
              WHEN home_team_goals = away_team_goals THEN 1
              ELSE 0
          END AS home_score,
          CASE
              WHEN home_team_goals < away_team_goals THEN 3
              WHEN home_team_goals = away_team_goals THEN 1
              ELSE 0
          END AS away_score
     FROM Matches),
 team_score_cte AS (
    (SELECT home_team_id AS team_id,
            home_score AS score,
            home_team_goals AS goal_for,
            away_team_goals AS goal_against
     FROM match_score_cte)
    UNION ALL
    (SELECT away_team_id AS team_id,
            away_score AS score,
            away_team_goals AS goal_for,
            home_team_goals AS goal_against
     FROM match_score_cte))

SELECT t.team_name,
       COUNT(t.team_name) AS matches_played,
       SUM(s.score) AS points,
       SUM(s.goal_for) AS goal_for,
       SUM(s.goal_against) AS goal_against,
       SUM(s.goal_for) - SUM(s.goal_against) AS goal_diff
FROM team_score_cte s
INNER JOIN Teams t ON s.team_id = t.team_id
GROUP BY t.team_name
ORDER BY points DESC,
         goal_diff DESC,
         t.team_name;

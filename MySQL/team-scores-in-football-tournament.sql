# Time:  O(nlogn)
# Space: O(n)

SELECT *
FROM
  (SELECT t.team_id,
          t.team_name,
          COALESCE(SUM(m.result), 0) AS num_points
   FROM TEAMS t
   LEFT JOIN
     (SELECT host_team AS team_id,
             3 AS RESULT
      FROM Matches
      WHERE host_goals > guest_goals
      UNION ALL
      SELECT host_team AS team_id,
             1 AS RESULT
      FROM Matches
      WHERE host_goals = guest_goals
      UNION ALL
      SELECT guest_team AS team_id,
             3 AS RESULT
      FROM Matches
      WHERE host_goals < guest_goals
      UNION ALL
      SELECT guest_team AS team_id,
             1 AS RESULT
      FROM Matches
      WHERE host_goals = guest_goals) m
   ON t.team_id = m.team_id
   GROUP BY t.team_id) r
ORDER BY num_points DESC,
         team_id;

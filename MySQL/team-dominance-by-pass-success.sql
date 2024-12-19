# Time:  O(plogp + t)
# Space: O(plogp + t)

SELECT t1.team_name,
       IF(p.time_stamp <= '45:00', 1, 2) AS half_number,
       SUM(IF(t1.team_name = t2.team_name, 1, -1)) AS dominance
FROM Passes p
     LEFT JOIN Teams t1 ON p.pass_from = t1.player_id
     LEFT JOIN Teams t2 ON p.pass_to = t2.player_id
GROUP BY 1, 2
ORDER BY 1, 2;

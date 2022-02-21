# Time:  O(nlogn)
# Space: O(n)

SELECT a.team_id,
       a.name,
       CAST(ROW_NUMBER() OVER(ORDER BY points DESC, name ASC) AS SIGNED) -
       CAST(ROW_NUMBER() OVER(ORDER BY points + points_change DESC, name ASC) as SIGNED) as rank_diff
FROM TeamPoints as a
INNER JOIN PointsChange as b
ON a.team_id=b.team_id;

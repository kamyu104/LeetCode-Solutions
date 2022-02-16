# Time:  O(nlogn)
# Space: O(n)

WITH player_match_seq_cte AS (
    SELECT player_id, match_day, result,
           ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY match_day) AS seq
    FROM matches),
player_match_group_id_cte AS (
    SELECT player_id,
           seq - ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY match_day) AS group_id
    FROM player_match_seq_cte
    WHERE result = 'Win'
),
player_match_group_cte AS (
    SELECT player_id, group_id, COUNT(*) as cnt
    FROM player_match_group_id_cte
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT a.player_id, IFNULL(MAX(b.cnt), 0) as longest_streak
FROM (SELECT DISTINCT player_id FROM matches) a
     LEFT JOIN
     player_match_group_cte b
     ON a.player_id = b.player_id
GROUP BY 1
ORDER BY NULL;

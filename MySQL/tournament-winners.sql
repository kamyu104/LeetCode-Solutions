# Time:  O(m + n + nlogn)
# Space: P(m + n)

SELECT group_id, 
       player_id 
FROM   (SELECT p.group_id, 
               ps.player_id, 
               Sum(ps.score) AS score 
        FROM   players p INNER JOIN
               (SELECT first_player AS player_id, 
                       first_score  AS score 
                FROM   matches 
                UNION ALL 
                SELECT second_player AS player_id,
                       second_score  AS score
                FROM   matches) ps 
        ON  p.player_id = ps.player_id 
        GROUP  BY ps.player_id 
        ORDER  BY group_id, 
                  score DESC, 
                  player_id) top_scores 
GROUP  BY group_id

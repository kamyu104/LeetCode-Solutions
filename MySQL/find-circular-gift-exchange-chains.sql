# Time:  O(n^2)
# Space: O(n^2)

# recursive cte, window function
WITH RECURSIVE cycles_cte AS (
    SELECT giver_id, 
           receiver_id, 
           gift_value, 
           giver_id AS start
    FROM SecretSanta
    UNION
    SELECT s.giver_id, 
           s.receiver_id, 
           s.gift_value, 
           c.start
    FROM SecretSanta s
    INNER JOIN cycles_cte c ON s.giver_id = c.receiver_id AND s.giver_id != c.start
),
cycle_start_length_value_triples_cte AS (
    SELECT start, 
           COUNT(*) AS chain_length, 
           SUM(gift_value) AS total_gift_value
    FROM cycles_cte
    GROUP BY 1
    ORDER BY NULL
),
unique_cycle_length_value_pairs_cte AS (
    SELECT chain_length, total_gift_value
    FROM cycle_start_length_value_triples_cte
    GROUP BY 1, 2
    ORDER BY NULL
)
SELECT RANK() OVER (ORDER BY chain_length DESC, total_gift_value DESC) AS chain_id,
       chain_length,
       total_gift_value
FROM unique_cycle_length_value_pairs_cte;

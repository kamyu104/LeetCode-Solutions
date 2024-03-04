# Time:  O(n)
# Space: O(n)

WITH prime_cte AS (
    SELECT item_type,
           FLOOR(500000 / SUM(square_footage)) * COUNT(*) AS item_count,
           FLOOR(500000 / SUM(square_footage)) * SUM(square_footage) AS total
    FROM Inventory
    WHERE item_type = 'prime_eligible'
), not_prime_cte AS (
    SELECT item_type,
           FLOOR((500000 - (SELECT total FROM prime_cte)) / SUM(square_footage)) * COUNT(*) AS item_count
    FROM Inventory
    WHERE item_type = 'not_prime'
)

(
    SELECT item_type, item_count
    FROM prime_cte
)
UNION
(
    SELECT item_type,  item_count
    FROM not_prime_cte
)
ORDER BY 2 DESC;

# Time:  O(nlogn)
# Space: O(n)

WITH rn_cte AS (
    SELECT id, drink, ROW_NUMBER() OVER () AS rn
    FROM CoffeeShop
),
group_cte AS (
    SELECT id, drink, rn, SUM(NOT ISNULL(drink)) OVER (ORDER BY rn) AS group_id
    FROM rn_cte
)

SELECT id, MAX(drink) OVER (PARTITION BY group_id) AS drink
FROM group_cte
ORDER BY rn;

# Time:  O(n^2)
# Space: O(n)

WITH metal_cte AS (
    SELECT symbol
    FROM Elements
    WHERE type = 'Metal'
), 
nonmetal_cte AS (
    SELECT symbol
    FROM Elements
    WHERE type = 'Nonmetal'
)

SELECT metal_cte.symbol AS metal,
       nonmetal_cte.symbol AS nonmetal 
FROM metal_cte CROSS JOIN nonmetal_cte;

# Time:  O(nlogn)
# Space: O(n)

WITH distinct_cte AS (
    SELECT DISTINCT x, y
    FROM Coordinates
    WHERE x != y
), normalized_cte AS (
    (
        SELECT (CASE WHEN x < y THEN x ELSE y END) AS x, (CASE WHEN x < y THEN y ELSE x END) AS y
        FROM distinct_cte
    )
    UNION ALL
    (
        SELECT x, y
        FROM Coordinates
        WHERE x = y
    )
)

SELECT x, y
FROM normalized_cte
GROUP BY x, y
HAVING COUNT(*) > 1
ORDER BY x, y;


# Time:  O(n^2)
# Space: O(n)
WITH rnk_cte AS (
    SELECT x, y, ROW_NUMBER() OVER () AS rnk
    FROM Coordinates
)

SELECT a.x, a.y
FROM rnk_cte AS a INNER JOIN rnk_cte AS b ON a.x = b.y and a.y = b.x and a.rnk != b.rnk
WHERE a.x <= a.y
GROUP BY a.x, a.y
ORDER BY a.x, a.y;

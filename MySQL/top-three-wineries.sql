# Time:  O(nlogn)
# Space: O(n)

WITH rank_cte AS (
    SELECT country,
           winery,
           SUM(points) AS total,
           ROW_NUMBER() OVER (PARTITION BY country ORDER BY SUM(points) DESC, winery) AS rnk
    FROM Wineries
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT country,
       MAX(CASE WHEN rnk = 1 THEN CONCAT(winery, ' (', total, ')') END) AS top_winery,
       COALESCE(MAX(CASE WHEN rnk = 2 THEN CONCAT(winery, ' (', total, ')') END), 'No second winery') AS second_winery,
       COALESCE(MAX(CASE WHEN rnk = 3 THEN CONCAT(winery, ' (', total, ')') END), 'No third winery') AS third_winery
FROM  rank_cte
WHERE rnk <= 3
GROUP BY 1
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)

WITH count_cte AS (
    SELECT voter, COUNT(*) AS cnt
    FROM Votes
    GROUP BY voter
    ORDER BY NULL
),
vote_cte AS (
    SELECT candidate, SUM(1 / cnt) AS total
    FROM Votes a INNER JOIN count_cte b ON a.voter = b.voter
    GROUP BY candidate
    HAVING candidate IS NOT NULL
    ORDER BY NULL
)

SELECT candidate
FROM vote_cte
WHERE total = (SELECT MAX(total) FROM vote_cte)
ORDER BY candidate;

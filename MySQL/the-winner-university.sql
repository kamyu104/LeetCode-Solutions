# Time:  O(n)
# Space: O(n)

WITH nyu_cte AS (
    SELECT COUNT(*) AS cnt FROM NewYork WHERE score >= 90
), cu_cte AS (
    SELECT COUNT(*) AS cnt FROM California WHERE score >= 90
)

SELECT
    (CASE
     WHEN N.cnt > C.cnt THEN 'New York University'
     WHEN N.cnt < C.cnt THEN 'California University'
     ELSE 'No Winner'
     END) AS winner
FROM nyu_cte N, cu_cte C;

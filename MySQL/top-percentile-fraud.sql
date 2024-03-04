# Time:  O(nlogn)
# Space: O(n)

WITH pct_rank_cte AS (
    SELECT *,
           PERCENT_RANK() OVER(PARTITION BY state ORDER BY fraud_score DESC) AS pct_rank
    FROM Fraud
)

SELECT policy_id, state, fraud_score
FROM pct_rank_cte
WHERE pct_rank <= 0.05
ORDER BY 2, 3 DESC, 1;

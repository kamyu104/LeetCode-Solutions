# Time:  O(nlogn)
# Space: O(n)

# window function
WITH year_spend_cte AS (
    SELECT YEAR(transaction_date) AS year,
           product_id,
           SUM(spend) AS spend 
    FROM user_transactions
    GROUP BY 1, 2
    ORDER BY NULL
), prev_year_cte AS (
    SELECT year,
           product_id,
           spend AS curr_year_spend,
           LAG(spend) OVER (PARTITION BY product_id ORDER BY year) AS prev_year_spend,
           LAG(year) OVER (PARTITION BY product_id ORDER BY year) AS prev_year
    FROM year_spend_cte
)

SELECT year,
       product_id,
       curr_year_spend,
       IF(year = prev_year + 1, prev_year_spend, NULL) AS prev_year_spend,
       ROUND(100.0 * IF(year = prev_year + 1, (curr_year_spend - prev_year_spend) / prev_year_spend, NULL), 2) AS yoy_rate
FROM prev_year_cte
ORDER BY 2, 1;

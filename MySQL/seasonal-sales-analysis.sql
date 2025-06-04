# Time:  O(nlogn)
# Space: O(n)

# window function
WITH season_category_cte AS (
    SELECT CASE 
                WHEN MONTH(sale_date) IN (12, 1, 2) THEN 'Winter'
                WHEN MONTH(sale_date) IN (3, 4, 5) THEN 'Spring'
                WHEN MONTH(sale_date) IN (6, 7, 8) THEN 'Summer'
                WHEN MONTH(sale_date) IN (9, 10, 11) THEN 'Fall'
           END AS season,
           category,
           SUM(quantity) AS total_quantity,
           SUM(quantity * price) AS total_revenue
    FROM sales s LEFT JOIN products p ON s.product_id = p.product_id
    GROUP BY 1, 2
    ORDER BY NULL
),
season_category_rank_cte AS (
    SELECT season, category, total_quantity, total_revenue,
           RANK() OVER (PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC) AS ranking
    FROM season_category_cte
)

SELECT season, category, total_quantity, total_revenue
FROM season_category_rank_cte
WHERE ranking = 1
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)

WITH date_cte AS (
    (
        SELECT 1 AS week_of_month,
               '2023-11-03' AS purchase_date
    )
    UNION ALL
    (
        SELECT 2 AS week_of_month,
               '2023-11-10' AS purchase_date
    )
    UNION ALL 
    (
        SELECT 3 AS week_of_month,
               '2023-11-17' AS purchase_date
    )
    UNION ALL 
    (
        SELECT 4 AS week_of_month,
               '2023-11-24' AS purchase_date
    )
)

SELECT a.week_of_month,
       a.purchase_date,
       COALESCE(SUM(b.amount_spend), 0) AS total_amount
FROM date_cte a LEFT JOIN Purchases b ON a.purchase_date = b.purchase_date
GROUP BY 1, 2
ORDER BY 1;

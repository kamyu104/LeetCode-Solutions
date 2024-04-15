# Time:  O(n)
# Space: O(n)

WITH weeks_cte AS (
   SELECT 1 AS week_of_month
   UNION ALL
   SELECT 2
   UNION ALL
   SELECT 3
   UNION ALL
   SELECT 4
),
memberships_cte AS (
   SELECT 'Premium' AS membership
   UNION ALL
   SELECT 'VIP'
), friday_purchases_cte AS (
    SELECT WEEK(purchase_date) - WEEK('2023-11-01') + 1 AS week_of_month,
           membership,
           SUM(amount_spend) AS total_amount
    FROM Purchases INNER JOIN Users USING(user_id)
    WHERE DAYOFWEEK(purchase_date) = 6
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT week_of_month, membership, COALESCE(total_amount, 0) AS total_amount
FROM weeks_cte CROSS JOIN memberships_cte
     LEFT JOIN friday_purchases_cte USING(week_of_month, membership)
ORDER BY 1, 2;

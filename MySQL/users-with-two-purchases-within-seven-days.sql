# Time:  O(nlogn)
# Space: O(n)

WITH purchase_cte AS
(
    SELECT user_id,
           purchase_date,
           LAG(purchase_date) OVER (PARTITION BY user_id
                                    ORDER BY purchase_date) AS prev_purchase_date
    FROM purchases
)

SELECT DISTINCT user_id
FROM  purchase_cte
WHERE DATEDIFF(purchase_date, prev_purchase_date) <= 7;

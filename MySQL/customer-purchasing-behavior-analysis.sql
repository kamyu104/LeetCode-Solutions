# Time:  O(nlogn)
# Space: O(n)
# window function

WITH transaction_product_cte AS (
    SELECT t.*, p.category
    FROM Transactions AS t INNER JOIN Products AS p ON t.product_id = p.product_id
    ORDER BY NULL
), customer_category_cte AS (
    SELECT customer_id,
           category,
           SUM(amount) AS amount,
           COUNT(*) AS cnt,
           MAX(transaction_date),
           FIRST_VALUE(category) OVER (PARTITION BY customer_id ORDER BY COUNT(*) DESC, MAX(transaction_date) DESC) AS top_category
    FROM transaction_product_cte 
    GROUP BY 1, 2
    ORDER BY NULL
)

SELECT customer_id,
       ROUND(SUM(amount), 2) AS total_amount,
       SUM(cnt) AS transaction_count,
       COUNT(*) AS unique_categories,
       ROUND(1.0 * SUM(amount) / SUM(cnt), 2) AS avg_transaction_amount,
       top_category,
       ROUND((SUM(cnt) * 10.0 + SUM(amount) / 100.0), 2) AS loyalty_score
FROM customer_category_cte
GROUP BY 1
ORDER BY 7 DESC, 1;

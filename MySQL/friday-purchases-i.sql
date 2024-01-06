# Time:  O(nlogn)
# Space: O(n)

SELECT WEEK(purchase_date) - WEEK('2023-11-01') + 1 AS week_of_month,
	     purchase_date,
       SUM(amount_spend) AS total_amount
FROM Purchases
WHERE DAYOFWEEK(purchase_date) = 6
GROUP BY 2
ORDER BY 1;

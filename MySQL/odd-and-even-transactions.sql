# Time:  O(nlogn)
# Space: O(1)

SELECT transaction_date, 
       SUM(IF(amount%2 != 0, amount, 0)) AS odd_sum,
       SUM(IF(amount%2 = 0, amount, 0)) AS even_sum
FROM transactions
GROUP BY 1
ORDER BY 1;

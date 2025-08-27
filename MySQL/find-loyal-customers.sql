# Time:  O(nlogn)
# Space: O(n)

SELECT customer_id
FROM customer_transactions 
GROUP BY 1 
HAVING SUM(transaction_type = 'purchase') >= 3
   AND DATEDIFF(MAX(transaction_date), MIN(transaction_date)) >= 30 
   AND (SUM(transaction_type = 'refund') / COUNT(*)) * 100 < 20
ORDER BY 1;

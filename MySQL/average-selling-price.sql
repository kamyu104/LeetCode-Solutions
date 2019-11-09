# Time:  O(n)
# Space: O(n)

SELECT b.product_id, 
       ROUND(SUM(a.units * b.price) / SUM(a.units), 2) AS average_price 
FROM   UnitsSold AS a 
       INNER JOIN Prices AS b 
               ON a.product_id = b.product_id 
WHERE  a.purchase_date BETWEEN b.start_date AND b.end_date 
GROUP  BY product_id; 

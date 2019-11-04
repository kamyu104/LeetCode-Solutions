# Time:  O(n), n is the number of delivery
# Space: O(m), m is the number of customer

SELECT Round(100 * Sum(order_date = customer_pref_delivery_date) / 
                    Count(DISTINCT customer_id), 2) AS immediate_percentage 
FROM   delivery 
WHERE  ( customer_id, order_date ) IN (SELECT customer_id, 
                                              Min(order_date) 
                                       FROM   delivery 
                                       GROUP  BY customer_id) 
 

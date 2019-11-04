# Time:  O(n)
# Space: O(1)

SELECT Round(100 * Sum(order_date = customer_pref_delivery_date) / Count(*), 2) 
       AS 
       immediate_percentage 
FROM   delivery;

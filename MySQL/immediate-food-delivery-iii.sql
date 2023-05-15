# Time:  O(nlogn)
# Space: O(n)

SELECT
    order_date,
    ROUND(SUM(CASE 
        WHEN order_date = customer_pref_delivery_date THEN 1 
        ELSE 0 
    END)*100.0 / COUNT(*),
    2) AS immediate_percentage 
FROM Delivery 
GROUP BY 1 
ORDER BY 1;

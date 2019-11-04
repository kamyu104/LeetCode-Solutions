# Time:  O(m + n)
# Space: O(m + n)

SELECT u.user_id                   AS buyer_id, 
       u.join_date, 
       Ifnull(t.orders_in_2019, 0) AS orders_in_2019 
FROM   users u 
       LEFT JOIN (SELECT buyer_id        AS user_id, 
                         Count(buyer_id) AS orders_in_2019 
                  FROM   orders 
                  WHERE  Year(order_date) = 2019 
                  GROUP  BY buyer_id)t 
              ON u.user_id = t.user_id 

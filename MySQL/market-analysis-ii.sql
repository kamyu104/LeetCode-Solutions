# Time:  O(m + n), m is the number of users, n is the number of orders
# Space: O(m + n)

SELECT user_id AS seller_id, 
       IF(item_brand = favorite_brand, 'yes', 'no') AS 2nd_item_fav_brand 
FROM   (SELECT user_id, 
               favorite_brand, 
               (SELECT    item_id
                FROM      orders o 
                WHERE     user_id = o.seller_id 
                ORDER BY order_date limit 1, 1) item_id
        FROM   users) u
        LEFT JOIN items i 
        ON        u.item_id = i.item_id 

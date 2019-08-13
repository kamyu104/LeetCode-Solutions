# Time:  O(m + n), m is the number of users, n is the number of orders
# Space: O(m + n)

SELECT user_id AS seller_id, 
       CASE 
              WHEN item_brand != favorite_brand THEN 'no' 
              WHEN item_brand IS NULL THEN 'no' 
              ELSE 'yes' 
       END AS 2nd_item_fav_brand 
FROM   (SELECT user_id, 
               favorite_brand, 
               (SELECT    item_brand 
                FROM      orders o 
                LEFT JOIN items i 
                ON        o.item_id = i.item_id 
                WHERE     user_id = o.seller_id 
                ORDER BY order_date limit 1, 1) item_brand 
        FROM   users) u

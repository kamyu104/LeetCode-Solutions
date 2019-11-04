# Time:  O(mlogn), m is the number of unique product id, n is the number of changed dates
# Space: O(m)

SELECT t1.product_id                      AS product_id, 
       IF(Isnull(t2.price), 10, t2.price) AS price 
FROM   (SELECT DISTINCT product_id 
        FROM   products) AS t1 
       left join (SELECT product_id, 
                         new_price AS price 
                  FROM   products 
                  WHERE  ( product_id, change_date ) IN (SELECT product_id, 
                                                                Max(change_date) 
                                                         FROM   products 
                                                         WHERE change_date <= '2019-08-16' 
                                                         GROUP  BY product_id)) 
                 AS t2 
              ON t1.product_id = t2.product_id 

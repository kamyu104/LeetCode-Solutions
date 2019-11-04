# Time:  O(m + n)
# Space: O(n)

SELECT b.book_id, 
       b.NAME 
FROM   books AS b 
       LEFT JOIN orders AS o 
              ON b.book_id = o.book_id 
                 AND dispatch_date BETWEEN '2018-06-23' AND '2019-6-23' 
WHERE  Datediff('2019-06-23', b.available_from) > 30 
GROUP BY book_id 
HAVING Sum(IFNULL(o.quantity, 0)) < 10 ORDER  BY NULL 

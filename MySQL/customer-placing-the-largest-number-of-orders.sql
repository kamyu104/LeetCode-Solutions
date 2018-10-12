# Time:  O(n)
# Space: O(n)

SELECT customer_number
FROM orders
GROUP BY customer_number
HAVING COUNT(order_number) = 
     (SELECT MAX(*)
     FROM
        (SELECT COUNT(*) AS cnt
        FROM
            orders
        GROUP BY customer_number
        ORDER BY NULL
        ) AS cnt_tbl
     )
ORDER BY NULL
LIMIT 1
;


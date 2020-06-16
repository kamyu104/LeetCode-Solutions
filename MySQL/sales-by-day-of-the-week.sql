# Time:  O(m + n)
# Space: O(n)

SELECT a.item_category AS 'CATEGORY',
       sum(CASE
               WHEN weekday(b.order_date) = 0 THEN b.quantity
               ELSE 0
           END) AS 'MONDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 1 THEN b.quantity
               ELSE 0
           END) AS 'TUESDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 2 THEN b.quantity
               ELSE 0
           END) AS 'WEDNESDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 3 THEN b.quantity
               ELSE 0
           END) AS 'THURSDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 4 THEN b.quantity
               ELSE 0
           END) AS 'FRIDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 5 THEN b.quantity
               ELSE 0
           END) AS 'SATURDAY',
       sum(CASE
               WHEN weekday(b.order_date) = 6 THEN b.quantity
               ELSE 0
           END) AS 'SUNDAY'
FROM items a
LEFT JOIN orders b ON a.item_id = b.item_id
GROUP BY a.item_category
ORDER BY a.item_category;

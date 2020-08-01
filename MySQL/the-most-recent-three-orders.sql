# Time:  O(nlogn)
# Space: O(n)

SELECT customer_name,
       customer_id,
       order_id,
       order_date
FROM
  (SELECT @accu := (CASE
                        WHEN co.customer_id = @prev THEN @accu + 1
                        ELSE 1
                    END) AS n,
          @prev := co.customer_id AS customer_id,
          co.name AS customer_name,
          co.order_id AS order_id,
          co.order_date AS order_date
   FROM
     (SELECT @accu := 0, @prev := 0) AS init,
     (SELECT c.name, c.customer_id, o.order_id, o.order_date FROM
      Customers c
      INNER JOIN Orders o
      ON c.customer_id = o.customer_id
      ORDER BY c.name ASC, c.customer_id ASC, o.order_date DESC) AS co
  ) AS tmp
WHERE n < 4;

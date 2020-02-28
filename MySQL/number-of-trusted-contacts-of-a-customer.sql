# Time:  O(n + m + l + nlogn), n, m, l are the sizes of invoices, customers, contacts
# Space: O(n + m + l)

SELECT i.invoice_id, 
       c.customer_name, 
       i.price, 
       Ifnull(tmp.c_cnt, 0) AS contacts_cnt, 
       Ifnull(tmp.t_cnt, 0) AS trusted_contacts_cnt 
FROM   invoices i 
       LEFT JOIN (SELECT co.user_id, 
                         Count(co.user_id)       AS c_cnt, 
                         Count(cu.customer_name) AS t_cnt 
                  FROM   contacts co 
                         LEFT JOIN customers cu 
                                ON co.contact_name = cu.customer_name 
                                   AND co.contact_email = cu.email 
                  GROUP  BY co.user_id 
                  ORDER  BY NULL) tmp 
              ON i.user_id = tmp.user_id 
       LEFT JOIN customers c 
              ON i.user_id = c.customer_id 
ORDER  BY i.invoice_id;

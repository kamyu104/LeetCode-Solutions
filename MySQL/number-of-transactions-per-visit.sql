# Time:  O(m + n + rlogr)  
# Space: O(m + n)  

SELECT seq.transactions_count AS transactions_count,
       Ifnull(v.visits_count, 0) AS visits_count 
FROM   (SELECT @max_count := CAST(@max_count - 1 AS SIGNED) AS transactions_count 
        FROM   (SELECT @max_count := CAST(Ifnull(Max(count), 0) + 1 AS SIGNED)
                FROM   (SELECT Count(1) AS count 
                        FROM   transactions 
                        GROUP  BY user_id, 
                                  transaction_date 
                        ORDER  BY NULL) AS max) AS c
               CROSS JOIN (SELECT user_id 
                           FROM   visits 
                           UNION ALL 
                           SELECT user_id 
                           FROM   transactions) AS m_n
        WHERE  @max_count > 0 
        ORDER  BY transactions_count) AS seq
       LEFT JOIN (SELECT transactions_count, 
                         Count(1) AS visits_Count 
                  FROM   (SELECT Count(transaction_date) AS transactions_count 
                          FROM   visits AS v 
                                 LEFT JOIN transactions AS t 
                                        ON v.user_id = t.user_id 
                                           AND visit_date = transaction_date 
                          GROUP  BY v.user_id, 
                                    visit_date 
                          ORDER  BY NULL) AS visits_count 
                  GROUP  BY transactions_count) AS v 
              ON seq.transactions_count = v.transactions_count 

# Time:  O(m + n)  
# Space: O(m + n)  

SELECT seq.transactions_count AS transactions_count,
       Ifnull(v.visits_count, 0) AS visits_count 
FROM   (SELECT @count := CAST(@count + 1 AS SIGNED) AS transactions_count 
        FROM   (SELECT @count := -1, @max_count := Ifnull(Max(count), 0)
                FROM   (SELECT Count(1) AS count 
                        FROM   transactions 
                        GROUP  BY user_id, 
                                  transaction_date 
                        ORDER  BY NULL) AS tmp) AS c
               CROSS JOIN (SELECT user_id 
                           FROM   visits 
                           UNION ALL 
                           SELECT user_id 
                           FROM   transactions) AS m_n
        WHERE  @count < @max_count
       ) AS seq
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

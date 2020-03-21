# Time:  O(nlogn)
# Space: O(n)

SELECT product_id, 
       product_name, 
       report_year, 
       (DATEDIFF( 
           CASE WHEN YEAR(period_end)   > report_year THEN CONCAT(report_year, '-12-31') ELSE period_end   END,
           CASE WHEN YEAR(period_start) < report_year THEN CONCAT(report_year, '-01-01') ELSE period_start END
        ) + 1) * average_daily_sales AS total_amount
FROM   (SELECT s.product_id,
               product_name,
               period_start,
               period_end,
               average_daily_sales
        FROM  sales s
        INNER JOIN product p
        ON s.product_id = p.product_id
       ) AS r,
       (SELECT "2018" AS report_year 
        UNION ALL 
        SELECT "2019" 
        UNION ALL 
        SELECT "2020"
       ) AS y
WHERE  YEAR(period_start) <= report_year AND 
       YEAR(period_end)   >= report_year
GROUP  BY product_id,
          report_year
ORDER  BY product_id,
          report_year;
           
           
# Time:  O(nlogn)
# Space: O(n)
SELECT r.product_id, 
       product_name, 
       report_year, 
       total_amount 
FROM   ((SELECT product_id, 
                '2018'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
                             CASE WHEN period_end   > '2018-12-31' THEN '2018-12-31' ELSE period_end  END,
                             CASE WHEN period_start < '2018-01-01' THEN '2018-01-01' ELSE period_start END
                        ) + 1 AS days 
                 FROM   sales s) tmp 
         WHERE  days > 0) 
        UNION ALL
        (SELECT product_id, 
                '2019'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
                             CASE WHEN period_end   > '2019-12-31' THEN '2019-12-31' ELSE period_end  END,
                             CASE WHEN period_start < '2019-01-01' THEN '2019-01-01' ELSE period_start END
                        ) + 1 AS days 
                 FROM   sales s) tmp 
         WHERE  days > 0) 
        UNION ALL
        (SELECT product_id, 
                '2020'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
                             CASE WHEN period_end   > '2020-12-31' THEN '2020-12-31' ELSE period_end END,
                             CASE WHEN period_start < '2020-01-01' THEN '2020-01-01' ELSE period_start END
                        ) + 1 AS days 
                 FROM   sales s) tmp 
         WHERE  days > 0)
       ) r
       INNER JOIN product p
      ON r.product_id = p.product_id
ORDER  BY r.product_id, 
          report_year ;

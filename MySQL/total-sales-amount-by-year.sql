-- hard coded 
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
						        DAY, -- added
						        period_start,
                                CASE WHEN period_end   > '2018-12-31' THEN '2018-12-31' ELSE period_end END
                             --CASE WHEN period_start < '2018-01-01' THEN '2018-01-01' ELSE period_start END
                        ) + 1 AS days 
                 FROM   #Sales s
				  WHERE DATEPART(YEAR, period_start) = 2018 -- added
				 ) tmp 
         WHERE  days > 0) 
        UNION ALL
        (SELECT product_id, 
                '2019'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
						       DAY, -- added
						       period_start,
                               CASE WHEN period_end   > '2019-12-31' THEN '2019-12-31' ELSE period_end  END
                            -- CASE WHEN period_start < '2019-01-01' THEN '2019-01-01' ELSE period_start END
                      ) + 1 AS days 
                 FROM   #Sales s 
				  WHERE DATEPART(YEAR, period_start) = 2019 -- added
				  ) tmp 
         WHERE  days > 0) 
        UNION ALL
        (SELECT product_id, 
                '2020'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
						     DAY, -- added
						     period_start,-- added
                             CASE WHEN period_end > '2020-12-31' THEN '2020-12-31' ELSE period_end END
                            -- CASE WHEN period_start < '2020-01-01' THEN '2020-01-01' ELSE period_start END
                        ) + 1 AS days 
                 FROM   #Sales s
				  WHERE DATEPART(YEAR, period_start) = 2020 -- added
				 ) tmp 
         WHERE  days > 0)
		 -- added this additional UNION
			UNION ALL
        (SELECT product_id, 
                '2019'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
						     DAY, -- added
						     '2019-01-01',-- added -- start_date
                             CASE WHEN period_end > '2018-12-31' AND period_end > '2019-12-31' THEN '2019-12-31' ELSE period_end END
                        ) + 1 AS days 
                 FROM   #Sales s
				  WHERE DATEPART(YEAR, period_start) = 2018 -- added
				  AND DATEPART(YEAR, period_end) = 2020
				 ) tmp 
         WHERE  days > 0)
		 -- added this additional UNION
			UNION ALL
        (SELECT product_id, 
                '2020'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
						     DAY, -- added
						     '2020-01-01',-- added
							 period_end -- added
                        ) + 1 AS days 
                 FROM   #Sales s
				  WHERE DATEPART(YEAR, period_start) = 2019 -- added
				  AND DATEPART(YEAR, period_end) = 2020
				 ) tmp 
         WHERE  days > 0)
 		 -- added this additional UNION
		 UNION ALL
        (SELECT product_id, 
                '2020'                     AS report_year, 
                days * average_daily_sales AS total_amount 
         FROM   (SELECT product_id, 
                        average_daily_sales, 
                        DATEDIFF(
						     DAY, -- added
						     '2020-01-01',-- added
							 period_end -- added
                        ) + 1 AS days 
                 FROM   #Sales s
				  WHERE DATEPART(YEAR, period_start) = 2018 -- added
				  AND DATEPART(YEAR, period_end) = 2020 -- added
				 ) tmp 
         WHERE  days > 0)
       ) r
       INNER JOIN #Product p
      ON r.product_id = p.product_id
ORDER  BY r.product_id, 
          report_year ;

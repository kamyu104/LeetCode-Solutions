# Time:  O(nlogn)
# Space: O(n)

SELECT state     AS period_state, 
       Min(date) AS start_date, 
       Max(date) AS end_date 
FROM   (SELECT state, 
               date, 
               @rank := CASE 
                          WHEN @prev = state THEN @rank 
                          ELSE @rank + 1 
                        end   AS rank, 
               @prev := state AS prev 
        FROM   (SELECT * 
                FROM   (SELECT fail_date AS date, 
                               "failed"  AS state 
                        FROM   failed 
                        UNION ALL 
                        SELECT success_date AS date, 
                               "succeeded"  AS state 
                        FROM   succeeded) a 
                WHERE  date BETWEEN '2019-01-01' AND '2019-12-31' 
                ORDER  BY date ASC) b, 
               (SELECT @rank := 0, 
                       @prev := "unknown") c) d 
GROUP  BY d.rank 
ORDER  BY start_date ASC 

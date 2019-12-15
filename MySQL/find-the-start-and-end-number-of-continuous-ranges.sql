# Time:  O(n)
# Space: O(n)

SELECT Min(log_id) AS start_id, 
       Max(log_id) AS end_id 
FROM   (SELECT log_id, 
               @rank := CASE 
                          WHEN @prev = log_id - 1 THEN @rank 
                          ELSE @rank + 1 
                        end    AS rank, 
               @prev := log_id AS prev
        FROM   logs AS A, 
               (SELECT @rank := 0, 
                       @prev :=- 1) AS B) C 
GROUP  BY C.rank 
ORDER  BY NULL; 

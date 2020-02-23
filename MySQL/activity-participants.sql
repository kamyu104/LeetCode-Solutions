# Time:  O(n) 
# Space: O(n) 

SELECT activity 
FROM   friends 
GROUP  BY activity 
HAVING Count(1) NOT IN (SELECT Max(counts) 
                        FROM   (SELECT Count(1) AS counts 
                                FROM   friends 
                                GROUP  BY activity 
                                ORDER  BY NULL) a 
                        UNION ALL 
                        SELECT Min(counts) 
                        FROM   (SELECT Count(1) AS counts 
                                FROM   friends 
                                GROUP  BY activity 
                                ORDER  BY NULL) b) 
ORDER  BY NULL; 

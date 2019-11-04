# Time:  O(nlogn) 
# Space: O(n) 

SELECT person_name 
FROM   (SELECT person_name, 
               @accu := @accu + weight AS accu 
        FROM   (SELECT person_name, weight
                FROM   Queue 
                ORDER  BY turn) q, 
               (SELECT @accu := 0) vars) t 
WHERE  accu <= 1000 
ORDER  BY accu DESC 
LIMIT  1; 

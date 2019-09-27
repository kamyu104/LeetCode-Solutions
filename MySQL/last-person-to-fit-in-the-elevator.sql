# Time:  O(nlogn) 
# Space: O(n) 

SELECT person_name 
FROM   (SELECT person_name, 
               @accu := @accu + weight AS accu 
        FROM   (SELECT * 
                FROM   queue 
                ORDER  BY turn) q, 
               (SELECT @accu := 0) vars) tmp 
WHERE  accu <= 1000 
ORDER  BY accu DESC 
LIMIT  1; 

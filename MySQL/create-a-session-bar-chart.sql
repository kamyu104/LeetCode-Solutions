# Time:  O(n)
# Space: O(1)

SELECT '[0-5>'  AS bin, 
       Count(1) AS total 
FROM   sessions 
WHERE  duration >= 0 
       AND duration < 300 
UNION ALL
SELECT '[5-10>' AS bin, 
       Count(1) AS total 
FROM   sessions 
WHERE  duration >= 300 
       AND duration < 600 
UNION ALL 
SELECT '[10-15>' AS bin, 
       Count(1)  AS total 
FROM   sessions 
WHERE  duration >= 600 
       AND duration < 900 
UNION ALL 
SELECT '15 or more' AS bin, 
       Count(1)     AS total 
FROM   sessions 
WHERE  duration >= 900;

# Time:  O(n)
# Space: O(n)
SELECT
    t2.BIN,
    COUNT(t1.BIN) AS TOTAL
FROM (
SELECT
    CASE 
        WHEN duration/60 BETWEEN 0 AND 5 THEN "[0-5>"
        WHEN duration/60 BETWEEN 5 AND 10 THEN "[5-10>"
        WHEN duration/60 BETWEEN 10 AND 15 THEN "[10-15>"
        WHEN duration/60 >= 15 THEN "15 or more" 
        ELSE NULL END AS BIN
FROM Sessions
) t1 
RIGHT JOIN(
    SELECT "[0-5>"        AS BIN
    UNION ALL
    SELECT "[5-10>"       AS BIN
    UNION ALL
    SELECT "[10-15>"      AS BIN
    UNION ALL
    SELECT "15 or more"   AS BIN
) t2
ON t1.bin = t2.bin
GROUP BY t2.bin
ORDER BY NULL;

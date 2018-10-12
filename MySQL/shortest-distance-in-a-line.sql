# Time:  O(nlogn)
# Space: O(n)
SET @prev := -100000000; 
SELECT MIN(diff) AS shortest
FROM (SELECT (x - @prev) AS diff, @prev := x 
      FROM (SELECT * 
            FROM point 
            ORDER BY x) AS t1
     ) AS t2
;

SELECT MIN(P1.x - P2.x) AS shortest 
FROM (SELECT @id1:=0, @id2:=0) AS t,
     (SELECT @id1:=@id1+1 AS id, x FROM point ORDER BY x) AS P1
     JOIN
     (SELECT @id2:=@id2+1 AS id, x FROM point ORDER BY x) AS P2
     ON P1.id = P2.id + 1
WHERE P1.id > 1;

SELECT
    MIN(p2.x - p1.x) AS shortest
FROM
    point p1
        JOIN
    point p2 ON p1.x < p2.x
;


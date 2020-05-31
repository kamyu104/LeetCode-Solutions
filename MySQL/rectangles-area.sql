# Time:  O(n^2)
# Space: O(n^2)

SELECT *
FROM
  (SELECT a.id AS P1,
          b.id AS P2,
          abs(a.x_value - b.x_value) * abs(a.y_value - b.y_value) AS area
   FROM Points a
   INNER JOIN Points b ON a.id < b.id
   ORDER BY area DESC, P1, P2) r
WHERE area > 0;

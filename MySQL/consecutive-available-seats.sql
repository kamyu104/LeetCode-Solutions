# Time:  O(nlogn)
# Space: O(n)

SELECT DISTINCT c1.seat_id
FROM cinema c1 JOIN cinema c2
  ON ((c1.seat_id = c2.seat_id - 1) OR (c1.seat_id = c2.seat_id + 1))
  AND c1.free = true AND c2.free = true
ORDER BY c1.seat_id
;


# Time:  O(n * m + nlogn)
# Space: O(n * m)

SELECT a.flight_id,
       LEAST(COUNT(b.flight_id), a.capacity) AS booked_cnt, 
       GREATEST(COUNT(*)-a.capacity, 0) AS waitlist_cnt
FROM Flights a LEFT JOIN Passengers b ON a.flight_id = b.flight_id
GROUP BY 1
ORDER BY 1;

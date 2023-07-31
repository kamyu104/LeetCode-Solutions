# Time:  O(nlogn + m)
# Space: O(n + m)

WITH rank_cte AS (
    SELECT passenger_id, capacity,
           RANK() OVER (PARTITION BY a.flight_id ORDER BY booking_time) AS rnk
    FROM Passengers a LEFT JOIN Flights b ON a.flight_id = b.flight_id
)

SELECT passenger_id,
       IF (rnk <= capacity, 'Confirmed', 'Waitlist') AS Status
FROM rank_cte
ORDER BY passenger_id;

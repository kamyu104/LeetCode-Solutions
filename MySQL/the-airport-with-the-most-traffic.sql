# Time:  O(n)
# Space: O(n)

WITH flight_counts_cte AS
(SELECT a.airport_id, SUM(a.flights_count) AS flights_count 
 FROM
   (SELECT departure_airport AS airport_id, flights_count AS flights_count FROM Flights
    UNION ALL
    SELECT arrival_airport AS airport_id, flights_count AS flights_count FROM Flights
   ) a
 GROUP BY a.airport_id
 ORDER BY NULL
)

SELECT a.airport_id
FROM flight_counts_cte a, (SELECT MAX(b.flights_count) AS max_flights_count FROM flight_counts_cte b) c
WHERE a.flights_count = c.max_flights_count;

# Time:  O(p * b + blogb)
# Space: O(p * b)

WITH arrival_time_cte AS
(
    SELECT bus_id, b.arrival_time, capacity, count(passenger_id) AS prefix_sum
    FROM Buses b
    LEFT JOIN Passengers p
    ON p.arrival_time <= b.arrival_time
    GROUP BY bus_id
    ORDER BY arrival_time
)

SELECT bus_id, passengers_cnt
FROM
(
    SELECT bus_id, capacity, prefix_sum,
           @passengers_cnt := LEAST(capacity, prefix_sum-@accum) as passengers_cnt, 
           @accum := @accum + @passengers_cnt
    FROM arrival_time_cte,
         (SELECT @accum := 0,
                 @passengers_cnt := 0) init
) t
ORDER BY bus_id;

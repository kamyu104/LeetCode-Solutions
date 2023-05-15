# Time:  O(nlogn)
# Space: O(n)

SELECT
    bike_number,
    MAX(end_time) AS end_time 
FROM Bikes 
GROUP BY 1
ORDER BY 2 DESC;

# Time:  O(m + n)
# Space: O(n)

SELECT c.country_name,
       CASE
           WHEN AVG(w.weather_state * 1.0) <= 15.0 THEN 'Cold'
           WHEN AVG(w.weather_state * 1.0) >= 25.0 THEN 'Hot'
           ELSE 'Warm'
       END AS weather_type
FROM Countries AS c
INNER JOIN Weather AS w ON c.country_id = w.country_id
WHERE w.day BETWEEN '2019-11-01' AND '2019-11-30'
GROUP BY c.country_id;

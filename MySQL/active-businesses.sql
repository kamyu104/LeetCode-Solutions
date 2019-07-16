# Time:  O(n)
# Space: O(n)

SELECT business_id
FROM EVENTS
JOIN
  (SELECT event_type,
          avg(occurences) AS average
   FROM EVENTS
   GROUP BY event_type) AS TEMP ON Events.event_type = temp.event_type
AND Events.occurences > temp.average
GROUP BY business_id
HAVING count(DISTINCT Events.event_type) > 1
ORDER BY NULL

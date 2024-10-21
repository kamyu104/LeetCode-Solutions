# Time:  O(nlogn)
# Space: O(n)

SELECT state,
       GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') AS cities,
       SUM(IF(LEFT(city, 1) = LEFT(state, 1), 1, 0)) AS matching_letter_count
FROM cities
GROUP BY 1
HAVING COUNT(city) >= 3 AND matching_letter_count >= 1
ORDER BY 3 DESC, 1;

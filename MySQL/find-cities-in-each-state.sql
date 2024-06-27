# Time:  O(nlogn)
# Space: O(n)

SELECT state, GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') AS cities
FROM cities
GROUP BY 1
ORDER BY 1;

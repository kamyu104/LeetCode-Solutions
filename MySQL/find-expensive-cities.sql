# Time:  O(nlogn)
# Space: O(n)

SELECT city 
FROM Listings
GROUP BY city 
HAVING AVG(price)> (SELECT avg(price) FROM Listings)
ORDER BY 1;

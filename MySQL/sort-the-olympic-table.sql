# Time:  O(nlogn)
# Space: O(n)

SELECT country, gold_medals, silver_medals, bronze_medals
FROM Olympic
ORDER BY gold_medals DESC, silver_medals DESC, bronze_medals DESC, country ASC;

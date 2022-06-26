# Time:  O(nlogn)
# Space: O(n)

WITH city_day_degree_rank_cte AS (
    SELECT city_id, day, degree,
           ROW_NUMBER() OVER (PARTITION BY city_id ORDER BY degree DESC, day ASC) rnk
    FROM Weather
)

SELECT city_id, day, degree
FROM city_day_degree_rank_cte
WHERE rnk = 1
ORDER BY 1;

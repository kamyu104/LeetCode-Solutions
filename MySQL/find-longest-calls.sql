# Time:  O(nlogn)
# Space: O(n)

# window function
WITH rank_cte AS (
    SELECT contact_id AS id, type,
           ROW_NUMBER() OVER (PARTITION BY type ORDER BY duration DESC) AS row_num,
           TIME_FORMAT(SEC_TO_TIME(duration), '%H:%i:%s') AS duration_formatted
    FROM Calls
), top3_cte AS (
    SELECT *
    FROM rank_cte
    WHERE row_num <= 3
)

SELECT first_name, type, duration_formatted
FROM top3_cte INNER JOIN contacts USING (id)
ORDER BY 2, 3 DESC, 1 DESC;

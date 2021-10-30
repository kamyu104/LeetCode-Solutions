# Time:  O(m + n)
# Space: O(m + n)

WITH visits_cte AS
(
    SELECT a.member_id, name, COUNT(visit_id) AS visit_cnt
    FROM Members a
    LEFT JOIN Visits b
    ON a.member_id = b.member_id
    GROUP BY a.member_id
    ORDER BY NULL
),
purchases_cte AS 
(
    SELECT member_id, COUNT(1) AS purchase_cnt
    FROM Purchases a
    INNER JOIN Visits b
    ON a.visit_id = b.visit_id
    GROUP BY member_id
    ORDER BY NULL
)

SELECT a.member_id, name,
       CASE WHEN visit_cnt = 0 THEN 'Bronze'
       WHEN IFNULL(purchase_cnt, 0) / visit_cnt < 0.5 THEN 'Silver'
       WHEN IFNULL(purchase_cnt, 0) / visit_cnt < 0.8 THEN 'Gold'
       ELSE 'Diamond'
       END AS category
FROM visits_cte a
LEFT JOIN purchases_cte b
ON a.member_id = b.member_id;

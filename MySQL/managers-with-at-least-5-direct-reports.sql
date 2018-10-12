# Time:  O(n)
# Space: O(n)

SELECT
    Name
FROM
    Employee AS t1 INNER JOIN
    (SELECT
        ManagerId
    FROM
        Employee
    GROUP BY ManagerId
    HAVING COUNT(ManagerId) >= 5
    ORDER BY NULL) AS t2
    ON t1.Id = t2.ManagerId
;


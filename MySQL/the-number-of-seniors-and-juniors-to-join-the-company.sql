# Time:  O(nlogn)
# Space: O(n)

WITH senior_cte AS
(
    SELECT  'Senior' AS experience,
            IFNULL(MAX(salary_accu), 0) AS salary,
            IFNULL(MAX(rn), 0) AS rn
    FROM
    (
        SELECT  SUM(salary)  OVER(ORDER BY salary, employee_id) AS salary_accu,
                ROW_NUMBER() OVER(ORDER BY salary, employee_id) rn
        FROM    candidates
        WHERE   experience = 'Senior'
    ) a
    WHERE salary_accu <= 70000
),
junior_cte AS
(
    SELECT  'Junior' AS experience,
            IFNULL(MAX(salary_accu), 0) AS salary,
            IFNULL(MAX(rn), 0) AS rn
    FROM
    (
        SELECT  SUM(salary)  OVER(ORDER BY salary, employee_id) AS salary_accu,
                ROW_NUMBER() OVER(ORDER BY salary, employee_id) AS rn
        FROM    candidates
        WHERE   experience = 'Junior'
    ) a
    WHERE salary_accu + (SELECT salary FROM senior_cte) <= 70000
)

SELECT experience, rn AS accepted_candidates
FROM
(
    SELECT experience, rn FROM senior_cte
    UNION ALL
    SELECT experience, rn FROM junior_cte
) a;

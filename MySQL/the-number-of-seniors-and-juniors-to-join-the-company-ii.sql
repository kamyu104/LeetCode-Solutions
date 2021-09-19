# Time:  O(nlogn)
# Space: O(n)

WITH senior_cte AS
(
    SELECT  employee_id,
            salary_accu
    FROM
    (
        SELECT  employee_id,
                SUM(salary)  OVER(ORDER BY salary, employee_id) AS salary_accu
        FROM    candidates
        WHERE   experience = 'Senior'
    ) a
    WHERE salary_accu <= 70000
),
senior_max_cte AS
(
    SELECT IFNULL(MAX(salary_accu), 0) AS salary
    FROM senior_cte
),
junior_cte AS
(
    SELECT  employee_id
    FROM
    (
        SELECT  employee_id,
                SUM(salary)  OVER(ORDER BY salary, employee_id) AS salary_accu
        FROM    candidates
        WHERE   experience = 'Junior'
    ) a
    WHERE salary_accu + (SELECT salary FROM senior_max_cte) <= 70000
)

SELECT employee_id FROM senior_cte
UNION ALL
SELECT employee_id FROM junior_cte;

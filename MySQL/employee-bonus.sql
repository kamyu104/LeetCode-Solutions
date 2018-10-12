# Time:  O(n) if hash join, O(nlogn) if merge join
# Space: O(n)

SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT JOIN
    Bonus ON Employee.empid = Bonus.empid
WHERE
    Bonus.bonus < 1000 OR Bonus.bonus IS NULL
;


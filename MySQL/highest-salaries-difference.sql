# Time:  O(n)
# Space: O(n)

SELECT ABS(
    (
        SELECT MAX(salary)
        FROM Salaries
        WHERE DEPARTMENT = "Marketing"
    )
    - 
    (
        SELECT MAX(salary)
        FROM Salaries
        WHERE DEPARTMENT = "Engineering"
    )
) AS salary_difference;

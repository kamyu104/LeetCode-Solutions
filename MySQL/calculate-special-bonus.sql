# Time:  O(n)
# Space: O(n)

SELECT employee_id,
       IF(employee_id%2 = 1
          AND name NOT LIKE('M%'), salary, 0) AS bonus
FROM Employees;

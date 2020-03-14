# Time:  O(n)
# Space: O(n)

SELECT u.unique_id, e.name
FROM employees e
LEFT JOIN employeeuni u
ON e.id = u.id

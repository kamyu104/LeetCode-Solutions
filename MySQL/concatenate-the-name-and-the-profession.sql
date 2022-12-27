# Time:  O(nlogn)
# Space: O(n)

SELECT person_id,
       CONCAT(name, '(', SUBSTRING(profession, 1, 1), ')') AS name
FROM Person
ORDER BY person_id DESC;

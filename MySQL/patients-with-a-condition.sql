# Time:  O(n)
# Space: O(n)

SELECT * 
FROM Patients AS p
WHERE p.conditions REGEXP '^DIAB1| DIAB1';

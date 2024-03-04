# Time:  O(nlogn)
# Space: O(n)

SELECT N,
       CASE 
           WHEN P IS NULL THEN 'Root'
           WHEN N IN (SELECT DISTINCT P FROM Tree) THEN 'Inner'
           ELSE 'Leaf'
       END AS Type
FROM Tree
ORDER BY 1 ASC;

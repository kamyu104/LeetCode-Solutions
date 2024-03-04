# Time:  O(nlogn)
# Space: O(n)

SELECT candidate_id
FROM candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY 1
HAVING COUNT(skill) = 3
ORDER BY 1;

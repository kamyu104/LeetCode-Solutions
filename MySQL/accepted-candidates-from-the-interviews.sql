# Time:  O(m + n)
# Space: O(m + n)

SELECT candidate_id
FROM Candidates as a
INNER JOIN Rounds as b
ON a.interview_id = b.interview_id
WHERE years_of_exp >= 2
GROUP BY candidate_id
HAVING SUM(score) > 15
ORDER BY NULL;

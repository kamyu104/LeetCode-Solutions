# Time:  O(nlogn)
# Space: O(n)

SELECT
    name AS Name
FROM
    Candidate
        JOIN
    (SELECT
        Candidateid
    FROM
        Vote
    GROUP BY Candidateid
    ORDER BY COUNT(*) DESC
    LIMIT 1) AS Winner
WHERE
    Candidate.id = Winner.Candidateid
;


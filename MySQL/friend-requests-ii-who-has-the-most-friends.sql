# Time:  O(nlogn)
# Space: O(n)

SELECT ids as id, COUNT(*) AS num
   FROM
   (
        SELECT requester_id AS ids FROM request_accepted
        UNION ALL
        SELECT accepter_id FROM request_accepted
    ) AS tmp
GROUP BY ids
ORDER BY num DESC
LIMIT 1
;


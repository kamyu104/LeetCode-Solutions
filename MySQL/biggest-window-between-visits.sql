# Time:  O(nlogn)
# Space: O(n)

SELECT
    user_id,
    MAX(DATEDIFF(visit_date_after, visit_date)) AS biggest_window
FROM (
    SELECT
        user_id,
        visit_date,
        IFNULL(
            LEAD(visit_date, 1) OVER (
                PARTITION BY user_id
                ORDER BY visit_date
            ),
            '2021-1-1'
        ) AS visit_date_after
    FROM UserVisits
) tmp
GROUP BY 1
ORDER BY NULL;

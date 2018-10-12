# Time:  O(s * o)
# Space: O(s + o)

SELECT
    s.name
FROM
    salesperson AS s
WHERE
    s.sales_id NOT IN (SELECT
            o.sales_id
        FROM
            orders AS o
                LEFT JOIN
            company AS c ON o.com_id = c.com_id
        WHERE
            c.name = 'RED')
;


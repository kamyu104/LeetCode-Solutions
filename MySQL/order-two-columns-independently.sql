# Time:  O(nlogn)
# Space: O(n)

SELECT first_col, second_col
FROM (
    SELECT first_col, ROW_NUMBER() OVER(ORDER BY first_col ASC) AS rnk
    FROM Data
) a
INNER JOIN (
    SELECT second_col, ROW_NUMBER() OVER(ORDER BY second_col DESC) AS rnk
    FROM Data
) b
ON a.rnk = b.rnk;

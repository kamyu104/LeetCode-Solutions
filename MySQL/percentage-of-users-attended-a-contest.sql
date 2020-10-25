# Time:  O(m + nlogn)
# Space: O(n)

SELECT contest_id,
       (Round(Count(contest_id) * 10000 /
              (SELECT Count(*) FROM Users)) / 100) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY 2 DESC,
         1;

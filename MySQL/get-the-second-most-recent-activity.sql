# Time:  O(nlogn)
# Space: O(n)

SELECT *
FROM UserActivity
GROUP BY username
HAVING COUNT(1) = 1

UNION ALL

SELECT a.username,
       a.activity,
       a.startDate,
       a.endDate
FROM
  (SELECT @accu := (CASE
                        WHEN username = @prev THEN @accu + 1
                        ELSE 1
                    END) AS n,
          @prev := username AS username,
          activity,
          startDate,
          endDate
   FROM
        (SELECT @accu := 0, @prev := 0) AS init,
        UserActivity AS u
   ORDER BY username,
            endDate DESC) AS a
WHERE n = 2;

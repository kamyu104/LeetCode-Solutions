# Time:  O(nlogn)
# Space: O(n)

SELECT DISTINCT 
       r.id,
       r.name
FROM
  (SELECT a_l.id,
          a_l.name,
          @accu := CASE
                       WHEN a_l.name = @prev AND 
                            DATEDIFF(a_l.login_date, @login_date) = 1
                       THEN @accu + 1
                       ELSE 1
                   END AS accu,
          @prev := a_l.name AS prev,
          @login_date := a_l.login_date AS login_date
   FROM (
           (SELECT DISTINCT
                   a.id,
                   a.name,
                   l.login_date
            FROM accounts a
            LEFT JOIN logins l
            ON a.id = l.id
            ORDER BY a.id,
                     a.name,
                     l.login_date) a_l,
           (SELECT @accu := 0,
                   @prev := "",
                   @login_date := "") init
        )
  ) r
WHERE r.accu = 5;

# Time:  O(nlogn)
# Space: O(n)

WITH winners_cte AS
  ((SELECT gold_medal AS winner, contest_id
    FROM contests)
   UNION ALL
   (SELECT silver_medal AS winner, contest_id
    FROM contests)
   UNION ALL
   (SELECT bronze_medal AS winner, contest_id
    FROM contests)),
     consecutive_winners_cte AS
  (SELECT winner, contest_id, row_number() OVER (PARTITION BY winner ORDER BY contest_id) AS row_num
   FROM winners_cte),
     candidates_cte AS
  ((SELECT winner AS user_id
    FROM consecutive_winners_cte
    GROUP BY winner, contest_id - row_num
    HAVING count(1) >= 3
    ORDER BY NULL)
   UNION
   (SELECT gold_medal AS user_id
    FROM contests
    GROUP BY gold_medal
    HAVING count(1) >= 3
    ORDER BY NULL))
  
SELECT u.name, u.mail
FROM users u
INNER JOIN candidates_cte c ON u.user_id = c.user_id;

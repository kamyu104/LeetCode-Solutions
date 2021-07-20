# Time:  O(nlogn)
# Space: O(n)

WITH confirmation_time_cte AS
  (SELECT user_id,
          TIMESTAMPDIFF(SECOND,
                        time_stamp,
                        LEAD(time_stamp, 1) OVER (PARTITION BY user_id
                                                  ORDER BY time_stamp)) AS time_diff
   FROM Confirmations)

SELECT DISTINCT user_id
FROM confirmation_time_cte
WHERE time_diff <= 86400;

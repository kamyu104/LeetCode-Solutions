# Time:  O(nlogn)
# Space: O(n)

SELECT a.user_id,
       ROUND(a.avg_trial, 2) AS trial_avg_duration,
       ROUND(b.avg_paid, 2) AS paid_avg_duration
FROM (SELECT user_id, AVG(activity_duration) AS avg_trial
      FROM UserActivity
      WHERE activity_type = "free_trial"
      GROUP BY 1
      ORDER BY NULL) a
     INNER JOIN
     (SELECT user_id, AVG(activity_duration) AS avg_paid
      FROM UserActivity
      WHERE activity_type = "paid"
      GROUP BY 1
      ORDER BY NULL) b
     ON a.user_id = b.user_id
ORDER BY 1;

# Time:  O(nlogn)
# Space: O(n)

# window function
WITH events_cte AS (
    SELECT user_id,
           event_date,
           MAX(event_date) OVER (PARTITION BY user_id) AS max_event_date,
           event_type,
           plan_name,
           monthly_amount,
           MAX(monthly_amount) OVER (PARTITION BY user_id) AS max_historical_amount,
           DATEDIFF(MAX(event_date) OVER (PARTITION BY user_id),
                    MIN(event_date) OVER (PARTITION BY user_id)
           ) AS days_as_subscriber
    FROM subscription_events
)

SELECT user_id,
       plan_name AS current_plan,
       monthly_amount AS current_monthly_amount,
       max_historical_amount,
       days_as_subscriber
FROM events_cte AS e
WHERE event_date = max_event_date AND event_type != 'cancel'
  AND EXISTS (
      SELECT 1 FROM events_cte AS e2 WHERE e.user_id = e2.user_id AND e2.event_type = 'downgrade'
  )
  AND 2 * monthly_amount < max_historical_amount
  AND days_as_subscriber >= 60
ORDER BY 5 DESC, 1;

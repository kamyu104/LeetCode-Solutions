# Time:  O(n)
# Space: O(n)

SELECT COUNT(DISTINCT user_id) AS user_cnt
FROM Purchases
WHERE time_stamp >= startDate AND time_stamp <= endDate AND amount >= minamount

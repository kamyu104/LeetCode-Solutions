# Time:  O(nlogn)
# Space: O(n)

CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN
    SELECT DISTINCT user_id
    FROM Purchases
    WHERE time_stamp >= startDate AND time_stamp <= endDate AND amount >= minAmount
    ORDER BY user_id;
END

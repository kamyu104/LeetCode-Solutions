# Time:  O(n)
# Space: O(n)

SELECT 'Low Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income < 20000
UNION ALL
SELECT 'Average Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income BETWEEN 20000 AND 50000
UNION ALL
SELECT 'High Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income > 50000;

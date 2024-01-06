# Time:  O(nlogn)
# Space: O(n)

SELECT user_id
FROM Loans 
WHERE loan_type IN ('Refinance','Mortgage')
GROUP BY 1 
HAVING COUNT(DISTINCT loan_type) = 2
ORDER BY 1;

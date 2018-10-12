# Time:  O(nlogn)
# Space: O(n)

SELECT Id, Company, Salary FROM
(
SELECT e.Id, e.Salary, e.Company,  IF (@Prev = e.Company , @Rank := @Rank + 1, @Rank := 1) AS Rank, @Prev := e.Company
FROM Employee e , (SELECT @Rank := 0, @prev := 0) AS Temp ORDER BY e.Company, e.Salary, e.Id
) Ranking
INNER JOIN
(
SELECT COUNT(*) AS TotalCount, Company AS Name FROM Employee e2 GROUP BY e2.Company
) CompanyCount
ON CompanyCount.Name = Ranking.Company
WHERE Rank = floor((TotalCount+1)/2) OR Rank = floor((TotalCount+2)/2)


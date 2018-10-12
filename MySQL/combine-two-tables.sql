# Time:  O(n), n is size of Person Table
# Space: O(n)

SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address
       ON Person.PersonId=Address.PersonId


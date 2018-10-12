# Time:  O(n^2)
# Space: O(n)

DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id


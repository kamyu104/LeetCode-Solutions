# Time:  O(n)
# Space: O(1)

SELECT *,
       IF (x+y>z AND x+z>y AND y+z>x, "Yes","No") AS triangle
FROM triangle;


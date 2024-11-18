# Time:  O(nlogn)
# Space: O(n)

SELECT book_id,
       title,
       author,
       published_year
FROM books
WHERE rating is NULL
ORDER BY 1 ASC;

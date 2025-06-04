# Time:  O(nlogn)
# Space: O(n)

SELECT l.book_id, 
       l.title, 
       l.author, 
       l.genre, 
       l.publication_year, 
       l.total_copies AS current_borrowers
FROM borrowing_records b LEFT JOIN library_books l ON b.book_id = l.book_id
WHERE b.return_date IS NULL
GROUP BY 1, 2, 3, 4, 5, 6 
HAVING COUNT(*) = l.total_copies
ORDER BY 6 DESC, 2;

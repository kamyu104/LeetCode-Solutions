# Time:  O(r + nlogn)
# Space: O(r + n)

WITH rating_cte AS (
    SELECT book_id,
           MAX(session_rating) AS max_rating,
           MIN(session_rating) AS min_rating,
           SUM(CASE WHEN session_rating >= 4 OR session_rating <= 2 THEN 1 ELSE 0 END) AS extreme_ratings,
           COUNT(*) AS total_sessions
    FROM reading_sessions 
    GROUP BY 1
    ORDER BY NULL
)

SELECT b.book_id,
       title,
       author,
       genre,
       pages,
       (max_rating - min_rating) AS rating_spread,
       ROUND(extreme_ratings * 1.0 / total_sessions, 2) AS polarization_score
FROM rating_cte r INNER JOIN books b ON r.book_id = b.book_id
WHERE total_sessions >= 5
  AND max_rating >= 4
  AND min_rating <= 2
  AND extreme_ratings * 1.0 / total_sessions >= 0.6
ORDER BY 7 DESC, 2 DESC;

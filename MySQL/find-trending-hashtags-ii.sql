# Time:  O(n * l^2 + (n * l) * log(n * l))
# Space: O(n * l^2)

# recursive cte
WITH RECURSIVE hashtag_cte AS (
    SELECT CONCAT('#', SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, '#', -1), ' ', 1)) AS hashtag,
           SUBSTRING(tweet, 1, LENGTH(tweet) - LOCATE('#', REVERSE(tweet))) AS remain,
           tweet_date
    FROM Tweets
    UNION ALL
    SELECT CONCAT('#', SUBSTRING_INDEX(SUBSTRING_INDEX(remain, '#', -1), ' ', 1)) AS hashtag,
           SUBSTRING(remain, 1, LENGTH(remain) - LOCATE('#', REVERSE(remain))) AS remain,
           tweet_date
    FROM hashtag_cte
    WHERE LOCATE('#', remain) > 0
)

SELECT hashtag, COUNT(*) AS count
FROM hashtag_cte
WHERE tweet_date BETWEEN "2024-02-01" AND "2024-02-29"
GROUP BY hashtag
ORDER BY 2 DESC, 1 DESC
LIMIT 3;

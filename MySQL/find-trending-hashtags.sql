# Time:  O(nlogn)
# Space: O(n)

SELECT CONCAT('#', SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, '#', -1), ' ', 1)) AS hashtag,
       COUNT(*) AS hashtag_count
FROM Tweets
WHERE tweet_date BETWEEN "2024-02-01" AND "2024-02-29"
GROUP BY 1
ORDER BY 2 DESC, 1 DESC
LIMIT 3;

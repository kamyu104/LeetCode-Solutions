# Time:  O(n * l)
# Space: O(n * l)

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;

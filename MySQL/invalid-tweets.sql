# Time:  O(n)
# Space: O(n)

SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;

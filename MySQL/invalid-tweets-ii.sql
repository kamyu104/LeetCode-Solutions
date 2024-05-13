# Time:  O(n * l + nlogn)
# Space: O(n * l)

# string
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 140 OR
      LENGTH(content) - LENGTH(REPLACE(content, '@', '')) > 3 OR
      LENGTH(content) - LENGTH(REPLACE(content, '#', '')) > 3
ORDER BY 1;

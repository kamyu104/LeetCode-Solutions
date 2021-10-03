# Time:  O(nlogn)
# Space: O(n)

SELECT problem_id
FROM Problems
WHERE likes / (likes + dislikes) < 0.6
ORDER BY 1;

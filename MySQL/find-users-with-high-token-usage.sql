# Time:  O(nlogn)
# Space: O(n)

SELECT user_id,
       COUNT(prompt) AS prompt_count,
       ROUND(AVG(tokens), 2) AS avg_tokens
FROM prompts
GROUP BY 1
HAVING prompt_count >= 3 AND MAX(tokens) > avg_tokens
ORDER BY 3 DESC, 1;

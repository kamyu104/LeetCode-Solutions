# Time:  O(n * l^2 + (n * l) * log(n * l))
# Space: O(n * l^2)

# recursive cte
WITH RECURSIVE splitted_word_cte AS (
    SELECT content_id,
           content_text,
           SUBSTRING_INDEX(content_text, ' ', 1) AS word,
           SUBSTRING(content_text, INSTR(content_text, ' ') + 1, 255) AS remain,
           1 AS idx
    FROM user_content
    UNION ALL
    SELECT content_id,
           content_text,
           SUBSTRING_INDEX(remain, ' ', 1) AS word,
           IF(INSTR(remain, ' ') = 0, '', SUBSTRING(remain, INSTR(remain, ' ') + 1, 255)) AS remain,
           idx + 1 AS idx
    FROM splitted_word_cte
    WHERE remain != ''
),
formatted_word_cte AS (
    SELECT content_id,
           content_text,
           idx,
           word,
           CONCAT(UPPER(SUBSTRING(word, 1, 1)), LOWER(SUBSTRING(word, 2, 255))) AS formatted_word
    FROM splitted_word_cte
)

SELECT content_id,
       content_text AS original_text,
       GROUP_CONCAT(formatted_word ORDER BY idx SEPARATOR ' ') AS converted_text
FROM formatted_word_cte
GROUP BY 1, 2
ORDER BY 1;

# Time:  O(n * l^2 + (n * l) * log(n * l))
# Space: O(n * l^2)

# recursive cte
WITH RECURSIVE splitted_word_cte AS (
    SELECT content_id,
           content_text,
           '^' AS delim,
           CASE
               WHEN INSTR(content_text, ' ') = 0 AND INSTR(content_text, '-') = 0 THEN
                   content_text
               WHEN INSTR(content_text, ' ') != 0 AND INSTR(content_text, '-') = 0 THEN
                   SUBSTRING(content_text, 1, INSTR(content_text, ' ') - 1)
               WHEN INSTR(content_text, ' ') = 0 AND INSTR(content_text, '-') != 0 THEN 
                   SUBSTRING(content_text, 1, INSTR(content_text, '-') - 1)
               WHEN INSTR(content_text, ' ') != 0 AND INSTR(content_text, '-') != 0 THEN
                   SUBSTRING(content_text, 1, INSTR(content_text, IF(INSTR(content_text, ' ') < INSTR(content_text, '-'), ' ', '-')) - 1)
           END AS word,
           CASE
               WHEN INSTR(content_text, ' ') = 0 AND INSTR(content_text, '-') = 0 THEN
                   ''
               WHEN INSTR(content_text, ' ') != 0 AND INSTR(content_text, '-') = 0 THEN
                   SUBSTRING(content_text, INSTR(content_text, ' '), 255)
               WHEN INSTR(content_text, ' ') = 0 AND INSTR(content_text, '-') != 0 THEN
                   SUBSTRING(content_text, INSTR(content_text, '-'), 255)
               WHEN INSTR(content_text, ' ') != 0 AND INSTR(content_text, '-') != 0 THEN
                   SUBSTRING(content_text, INSTR(content_text, IF(INSTR(content_text, ' ') < INSTR(content_text, '-'), ' ', '-')), 255)
           END AS remain,
        1 AS idx
    FROM user_content
    UNION ALL
    SELECT 
        content_id,
        content_text,
        SUBSTR(remain, 1, 1) AS delim,
        CASE
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') = 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') = 0 THEN 
                SUBSTRING(remain, 2, 255)
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') != 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') = 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), 1, INSTR(SUBSTRING(remain, 2, 255), ' ') - 1)
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') = 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') != 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), 1, INSTR(SUBSTRING(remain, 2, 255), '-') - 1)
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') != 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') != 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), 1, INSTR(SUBSTRING(remain, 2, 255), IF(INSTR(SUBSTRING(remain, 2, 255), ' ') < INSTR(SUBSTRING(remain, 2, 255), '-'), ' ', '-')) - 1)
        END AS word,
        CASE
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') = 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') = 0 THEN
                ''
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') != 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') = 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), INSTR(SUBSTRING(remain, 2, 255), ' '), 255)
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') = 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') != 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), INSTR(SUBSTRING(remain, 2, 255), '-'), 255)
            WHEN INSTR(SUBSTRING(remain, 2, 255), ' ') != 0 AND INSTR(SUBSTRING(remain, 2, 255), '-') != 0 THEN 
                SUBSTRING(SUBSTRING(remain, 2, 255), INSTR(SUBSTRING(remain, 2, 255), IF(INSTR(SUBSTRING(remain, 2, 255), ' ') < INSTR(SUBSTRING(remain, 2, 255), '-'), ' ', '-')), 255)
        END AS remain,
        idx + 1
    FROM splitted_word_cte
    WHERE remain != ''
),
formatted_word_cte AS (
    SELECT content_id,
           content_text,
           idx,
           word,
           CONCAT(IF(delim = '^', '', delim), UPPER(SUBSTRING(word, 1, 1)), LOWER(SUBSTRING(word, 2, 255))) AS formatted_word
    FROM splitted_word_cte
)

SELECT content_id,
       content_text AS original_text,
       GROUP_CONCAT(formatted_word ORDER BY idx SEPARATOR '') AS converted_text
FROM formatted_word_cte
GROUP BY 1, 2
ORDER BY 1;

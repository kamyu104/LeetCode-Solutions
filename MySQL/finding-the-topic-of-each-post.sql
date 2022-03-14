# Time:  O(n * mlogm)
# Space: O(n * m)

SELECT post_id, 
       IFNULL(GROUP_CONCAT(DISTINCT topic_id ORDER BY topic_id ASC SEPARATOR ','), "Ambiguous!") AS topic
FROM posts a
LEFT JOIN keywords b
ON CONCAT(' ', LOWER(a.content), ' ') LIKE CONCAT('% ', LOWER(b.word), ' %')
GROUP BY post_id
ORDER BY NULL;

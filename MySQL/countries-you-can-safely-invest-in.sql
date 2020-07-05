# Time:  O(n)
# Space: O(n)

SELECT co.name AS country
FROM person p
INNER JOIN country co ON SUBSTRING(phone_number, 1, 3) = country_code
INNER JOIN calls c ON (p.id = c.caller_id OR p.id = c.callee_id)
GROUP BY co.name
HAVING AVG(duration) > (SELECT AVG(duration) as avg_duration FROM calls)
ORDER BY NULL;

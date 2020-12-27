# Time:  O(n)
# Space: O(n)

SELECT LEAST(from_id,to_id) as person1,
       GREATEST(from_id,to_id) as person2,
       COUNT(*) as call_count,
       SUM(duration) as total_duration
FROM Calls
GROUP BY person1, person2
ORDER BY NULL;

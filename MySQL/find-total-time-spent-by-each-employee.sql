# Time:  O(nlogn)
# Space: O(n)

SELECT event_day               AS day,
       emp_id,
       Sum(out_time - in_time) AS total_time
FROM   employees
GROUP  BY 1, 2
ORDER  BY 1, 2;

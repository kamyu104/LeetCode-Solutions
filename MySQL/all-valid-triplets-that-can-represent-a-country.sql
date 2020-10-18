# Time:  O(n^3)
# Space: O(n^3)

SELECT a.student_name AS member_A,
       b.student_name AS member_B,
       c.student_name AS member_c
FROM schoola a
INNER JOIN schoolb b ON (a.student_id != b.student_id
                         AND a.student_name != b.student_name)
INNER JOIN schoolc c ON (a.student_id != c.student_id
                         AND a.student_name != c.student_name)
AND (b.student_id != c.student_id
     AND b.student_name != c.student_name);

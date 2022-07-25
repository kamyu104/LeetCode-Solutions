# Time:  O(nlogn)
# Space: O(n)

SELECT student_id,
       department_id, 
       ROUND(100 * PERCENT_RANK() OVER (PARTITION BY department_id
                                        ORDER BY mark DESC)
             , 2) AS percentage 
FROM Students;


# Time:  O(nlogn)
# Space: O(n)
SELECT student_id,
       department_id, 
       ROUND(IFNULL(100 * (RANK()   OVER (PARTITION BY department_id ORDER BY mark DESC) - 1) / 
                          (COUNT(1) OVER (PARTITION BY department_id) - 1)
                    , 0)
             , 2) AS percentage 
FROM Students;

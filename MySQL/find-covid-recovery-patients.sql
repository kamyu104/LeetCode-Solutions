# Time:  O(n^2)
# Space: O(n^2)

SELECT p.patient_id,
       p.patient_name,
       p.age,
       DATEDIFF(MIN(t2.test_date), MIN(t1.test_date)) AS recovery_time
FROM covid_tests t1
INNER JOIN covid_tests t2 ON t1.patient_id = t2.patient_id AND t1.test_date < t2.test_date AND t1.result = 'Positive' AND t2.result = 'Negative'
INNER JOIN patients p ON t1.patient_id = p.patient_id
GROUP BY 1
ORDER BY 4, 2;

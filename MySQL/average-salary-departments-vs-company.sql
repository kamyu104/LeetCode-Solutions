# Time:  O(nlogn)
# Space: O(n)

SELECT department_salary.pay_month, department_id,
CASE
  WHEN department_avg < company_avg THEN 'lower'
  WHEN department_avg > company_avg THEN 'higher'
  ELSE 'same'
END AS comparison
FROM
(
  SELECT department_id, AVG(amount) AS department_avg, date_format(pay_date, '%Y-%m') AS pay_month
  FROM salary JOIN employee ON salary.employee_id = employee.employee_id
  GROUP BY department_id, pay_month
) AS department_salary
JOIN
(
  SELECT AVG(amount) AS company_avg,  date_format(pay_date, '%Y-%m') AS pay_month
  FROM salary
  GROUP BY date_format(pay_date, '%Y-%m')
) AS company_salary
ON department_salary.pay_month = company_salary.pay_month
;


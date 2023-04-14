SELECT
  a.employee_id,
  a.name,
  COUNT(b.employee_id) AS reports_count,
  ROUND(AVG(b.age)) AS average_age
FROM
  employees a
  JOIN employees b ON a.employee_id=b.reports_to
GROUP BY
  employee_id
ORDER BY
  employee_id
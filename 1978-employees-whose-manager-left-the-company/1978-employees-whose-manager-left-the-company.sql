SELECT
  a.employee_id
FROM
  employees a
  LEFT JOIN employees b ON a.manager_id=b.employee_id
WHERE
  a.salary<30000
  AND b.employee_id IS NULL
  AND a.manager_id IS NOT NULL
ORDER BY
  employee_id
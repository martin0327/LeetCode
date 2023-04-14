SELECT
  a.name
FROM
  employee a
  JOIN employee b ON a.id=b.managerid
GROUP BY
  a.id
HAVING
  COUNT(b.managerid)>=5
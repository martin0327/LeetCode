WITH
  t AS (
    SELECT
      num
    FROM
      mynumbers
    GROUP BY
      num
    HAVING
      COUNT(*)=1
  )
SELECT
  MAX(num) AS num
FROM
  t
UNION
SELECT
  NULL AS num
LIMIT
  1
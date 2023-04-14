WITH
  t AS (
    SELECT
      num,
      COUNT(num) AS cnt
    FROM
      mynumbers
    GROUP BY
      num
    HAVING
      cnt=1
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
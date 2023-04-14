WITH
  t AS (
    SELECT
      *,
      SUM(weight) OVER (
        ORDER BY
          turn
      ) AS cum_sum
    FROM
      queue
  )
SELECT
  person_name
FROM
  t
WHERE
  cum_sum<=1000
ORDER BY
  cum_sum desc
LIMIT
  1
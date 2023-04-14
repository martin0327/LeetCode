WITH
  t1 AS (
    SELECT
      COUNT(*) AS tot
    FROM
      users
  ),
  t2 AS (
    SELECT
      r.contest_id,
      COUNT(u.user_id) AS cnt
    FROM
      register r
      JOIN users u ON u.user_id=r.user_id
    GROUP BY
      contest_id
  )
SELECT
  t2.contest_id,
  ROUND(100*t2.cnt/t1.tot, 2) AS percentage
FROM
  t2
  JOIN t1
ORDER BY
  percentage desc,
  contest_id asc
SELECT
  contest_id,
  ROUND(
    100*COUNT(DISTINCT user_id)/(
      SELECT
        COUNT(*)
      FROM
        users
    ),
    2
  ) AS percentage
FROM
  register
GROUP BY
  contest_id
ORDER BY
  percentage desc,
  contest_id asc
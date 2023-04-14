WITH
  t AS (
    SELECT
      visited_on,
      SUM(amount) AS amount
    FROM
      customer
    GROUP BY
      visited_on
  )
SELECT
  a.visited_on,
  SUM(b.amount) AS amount,
  ROUND(AVG(b.amount), 2) AS average_amount
FROM
  t AS a
  JOIN t AS b ON a.visited_on>=b.visited_on
  AND a.visited_on<=b.visited_on+INTERVAL 6 DAY
GROUP BY
  a.visited_on
HAVING
  (COUNT(b.visited_on)=7)
ORDER BY
  visited_on
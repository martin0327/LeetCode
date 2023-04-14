WITH
  t AS (
    SELECT
      *,
      date_format (trans_date, '%Y-%m') AS month
    FROM
      transactions
  )
SELECT
  month,
  country,
  COUNT(*) AS trans_count,
  SUM(if (state='approved', 1, 0)) AS approved_count,
  SUM(amount) AS trans_total_amount,
  SUM(if (state='approved', amount, 0)) AS approved_total_amount
FROM
  t
GROUP BY
  month,
  country
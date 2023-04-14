WITH
  t1 AS (
    SELECT
      customer_id,
      COUNT(DISTINCT product_key) AS cnt
    FROM
      customer
    GROUP BY
      customer_id
  ),
  t2 AS (
    SELECT
      COUNT(*) AS cnt
    FROM
      product
  )
SELECT
  customer_id
FROM
  t1
  JOIN t2 USING (cnt)
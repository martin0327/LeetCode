WITH
  t1 AS (
    SELECT
      product_id,
      MAX(change_date) AS DATE
    FROM
      products
    WHERE
      change_date<='2019-08-16'
    GROUP BY
      product_id
  ),
  t2 AS (
    SELECT
      p.product_id,
      p.new_price AS price
    FROM
      products p
      JOIN t1 ON p.product_id=t1.product_id
      AND p.change_date=t1.date
  ),
  t3 AS (
    SELECT DISTINCT
      product_id
    FROM
      products
  )
SELECT
  t3.product_id,
  ifnull (t2.price, 10) AS price
FROM
  t3
  LEFT JOIN t2 ON t2.product_id=t3.product_id
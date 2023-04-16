WITH
    t AS (
        SELECT
            product_id,
            MIN(YEAR) AS first_year
        FROM
            sales
        GROUP BY
            product_id
    )
SELECT
    t.product_id,
    t.first_year,
    s.quantity,
    s.price
FROM
    t
    JOIN sales s ON t.product_id = s.product_id
    AND t.first_year = s.year
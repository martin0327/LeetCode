WITH
    t AS (
        SELECT
            customer_id,
            MIN(order_date) AS min_date
        FROM
            delivery
        GROUP BY
            customer_id
    )
SELECT
    ROUND(
        100 * AVG(
            IF(t.min_date = d.customer_pref_delivery_date, 1, 0)
        ),
        2
    ) AS immediate_percentage
FROM
    t
    JOIN delivery d ON t.min_date = d.order_date
    AND t.customer_id = d.customer_id
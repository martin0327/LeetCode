SELECT
    p.product_name,
    SUM(o.unit) AS unit
FROM
    products p
JOIN
    orders o
ON
    p.product_id = o.product_id
WHERE 
    month(o.order_date) = 2 
    and year(o.order_date) = 2020
GROUP BY
    p.product_id
HAVING
    unit >= 100
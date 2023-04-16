WITH
    t1 AS (
        SELECT
            *
        FROM
            insurance
        GROUP BY
            lat,
            lon
        HAVING
            COUNT(*) = 1
    ),
    t2 AS (
        SELECT
            tiv_2015
        FROM
            insurance
        GROUP BY
            tiv_2015
        HAVING
            COUNT(*) > 1
    )
SELECT
    ROUND(SUM(t1.tiv_2016), 2) AS tiv_2016
FROM
    t1
    JOIN t2 ON t1.tiv_2015 = t2.tiv_2015
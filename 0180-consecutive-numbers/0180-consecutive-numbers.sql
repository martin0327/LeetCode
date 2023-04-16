WITH
    t AS (
        (
            SELECT
                id,
                num
            FROM
                LOGS
        )
        UNION ALL
        (
            SELECT
                id -1 AS id,
                num
            FROM
                LOGS
        )
        UNION ALL
        (
            SELECT
                id + 1 AS id,
                num
            FROM
                LOGS
        )
    )
SELECT
    distinct num AS consecutivenums
FROM
    t
GROUP BY
    id,
    num
HAVING
    COUNT(*) >= 3
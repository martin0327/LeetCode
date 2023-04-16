WITH
    t AS (
        SELECT
            score,
            RANK() OVER (
                ORDER BY
                    score DESC
            ) AS id
        FROM
            scores
        GROUP BY
            score
        ORDER BY
            score DESC
    )
SELECT
    s.score,
    t.id AS "rank"
FROM
    scores s
    JOIN t ON s.score = t.score
ORDER BY
    s.score DESC
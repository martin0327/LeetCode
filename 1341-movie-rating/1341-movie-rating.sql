(
  SELECT
    u.name AS results
  FROM
    users u
    JOIN movierating r USING (user_id)
  GROUP BY
    u.user_id
  ORDER BY
    COUNT(*) desc,
    u.name asc
  LIMIT
    1
)
UNION
(
  SELECT
    m.title AS results
  FROM
    movies m
    JOIN movierating r USING (movie_id)
  WHERE
    date_format (r.created_at, '%Y-%m')='2020-02'
  GROUP BY
    m.movie_id
  ORDER BY
    AVG(rating) desc,
    m.title asc
  LIMIT
    1
)
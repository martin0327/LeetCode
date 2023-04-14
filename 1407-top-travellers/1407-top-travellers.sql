SELECT
  u.name,
  (
    CASE
      WHEN SUM(r.distance) IS NULL THEN 0
      ELSE SUM(r.distance)
    END
  ) AS travelled_distance
FROM
  users u
  LEFT JOIN rides r ON u.id=r.user_id
GROUP BY
  r.user_id
ORDER BY
  travelled_distance desc,
  name asc
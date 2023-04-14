SELECT
  *
FROM
  users
WHERE
  mail REGEXP '^[a-zA-Z][0-9a-zA-Z_.-]*@leetcode\\.com$';
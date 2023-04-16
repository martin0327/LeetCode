WITH
    t AS (
        SELECT
            e.departmentid,
            MAX(e.salary) AS salary,
            d.name
        FROM
            employee e
            JOIN department d ON d.id = e.departmentid
        GROUP BY
            departmentid
    )
SELECT
    t.name AS department,
    e.name AS employee,
    t.salary
FROM
    t
    JOIN employee e ON t.departmentid = e.departmentid
    AND t.salary = e.salary
# Write your MySQL query statement below
select user_id, concat(ucase(left(name,1)),lower(substring(name,2))) as name
from users
order by user_id

# Write your MySQL query statement below
select a.name as Employee
from employee as a
join employee as b
on a.managerid = b.id
where a.salary > b.salary

# Write your MySQL query statement below
with t as(
  select employee_id, count(employee_id) as cnt from employee
  group by employee_id
)
select e.employee_id, e.department_id from employee e
join t 
on e.employee_id = t.employee_id 
where t.cnt = 1 
or e.primary_flag = 'Y'
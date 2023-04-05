# Write your MySQL query statement below
select a.unique_id, b.name from employees b
left join employeeuni a on a.id=b.id
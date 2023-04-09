select 
(
    select distinct salary from employee
    order by salary desc
    LIMIT 1, 1
) as SecondHighestSalary
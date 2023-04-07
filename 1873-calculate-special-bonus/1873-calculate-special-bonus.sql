# Write your MySQL query statement below
select employee_id, (case
                    when employee_id%2=1 
                    and name not LIKE 'M%' then salary
                    else 0
                    end) as bonus
from employees
order by employee_id
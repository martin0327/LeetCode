# Write your MySQL query statement below
with t as (
    select 
        customer_number, 
        count(customer_number) as cnt 
    from 
        orders 
    group by 
        customer_number
)
select 
    customer_number 
from 
    t 
where 
    cnt = (select max(cnt) from t ) 

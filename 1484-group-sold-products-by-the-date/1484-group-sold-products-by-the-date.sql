# Write your MySQL query statement below
select 
  sell_date, 
  count(distinct product) as num_sold,
  group_concat(distinct product order by product asc) as products
from activities
group by sell_date
# Write your MySQL query statement below
with temp as (select p.product_id, u.purchase_date, p.price, u.units from prices as p
join unitssold as u
on p.start_date <= u.purchase_date 
and p.end_date >= u.purchase_date
and p.product_id = u.product_id)
select product_id, round(sum(price*units) / sum(units),2) as average_price
from temp
group by product_id

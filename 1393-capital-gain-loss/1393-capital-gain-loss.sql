# Write your MySQL query statement below
select stock_name, sum(price * (case operation 
    when 'Buy' then -1 
    when 'Sell' then 1 END)) as capital_gain_loss
from stocks
group by stock_name
# Write your MySQL query statement below
with t as(
    select c.name as color, o.com_id, o.sales_id from orders as o
    join company c
    on c.com_id = o.com_id
),
t2 as ((select s.name, sum(if(t.color = 'RED',1,0)) as cnt from salesperson s
left join t
on s.sales_id = t.sales_id
group by s.name))
select name from t2
where cnt = 0

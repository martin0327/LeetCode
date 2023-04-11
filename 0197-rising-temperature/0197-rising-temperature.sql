# Write your MySQL query statement below
with t as (
    select date_add(recordDate, INTERVAL 1 DAY) as nextday, temperature 
    from weather
) 
select id from weather w
join t 
on t.nextday = w.recorddate 
where w.temperature - t.temperature > 0

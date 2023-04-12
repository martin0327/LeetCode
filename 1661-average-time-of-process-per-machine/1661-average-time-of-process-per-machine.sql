# Write your MySQL query statement below
with a as (select 
    machine_id, sum(timestamp) / count(activity_type) as t
from activity
where activity_type = 'end'
group by machine_id),
b as (select
    machine_id, sum(timestamp) / count(activity_type) as t
from activity
where activity_type = 'start'
group by machine_id)
select a.machine_id, round(a.t - b.t,3) as processing_time from a
join b
on a.machine_id = b.machine_id

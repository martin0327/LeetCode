# Write your MySQL query statement below
select activity_date as day, count(distinct user_id) as active_users
from activity
where date_add(activity_date, interval 30 day) > "2019-07-27"
and activity_date <= "2019-07-27"
group by activity_date
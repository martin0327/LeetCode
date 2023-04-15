select
    s.user_id,
    round(avg(if(action = 'confirmed', 1, 0)), 2) as confirmation_rate
from
    signups s
    left join confirmations c on s.user_id = c.user_id
group by
    s.user_id
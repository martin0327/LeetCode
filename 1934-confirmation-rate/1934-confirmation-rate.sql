with
    t1 as (
        select
            user_id,
            count(*) as cnt
        from
            confirmations
        where
            action = 'confirmed'
        group by
            user_id
    ),
    t2 as (
        select
            user_id,
            count(*) as cnt
        from
            confirmations
        group by
            user_id
    )
select
    s.user_id,
    round(
        if(
            t1.cnt is null
            or t2.cnt is null
            or t2.cnt = 0,
            0,
            t1.cnt / t2.cnt
        ),
        2
    ) as confirmation_rate
from
    signups as s
    left join t1 on s.user_id = t1.user_id
    left join t2 on s.user_id = t2.user_id
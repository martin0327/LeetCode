with
    t1 as (
        select
            player_id,
            min(event_date) as date
        from
            activity
        group by
            player_id
    )
select
    round(
        count(t1.player_id) / (
            select
                count(distinct player_id)
            from
                activity
            limit
                1
        ),
        2
    ) as fraction
from
    t1
    join activity t2 on date_add(t1.date, interval 1 day) = t2.event_date
    and t1.player_id = t2.player_id
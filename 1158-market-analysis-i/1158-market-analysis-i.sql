with
  t as (
    select
      order_date,
      buyer_id
    from
      orders
    where
      year (order_date) = 2019
  )
select
  u.user_id as buyer_id,
  u.join_date,
  count(t.buyer_id) as orders_in_2019
from
  users u
  left join t on u.user_id = t.buyer_id
group by
  u.user_id
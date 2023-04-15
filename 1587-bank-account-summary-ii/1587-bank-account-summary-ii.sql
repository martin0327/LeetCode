select
  u.name,
  sum(t.amount) as balance
from
  users u
  join transactions t on u.account = t.account
group by
  u.name
having
  balance > 10000
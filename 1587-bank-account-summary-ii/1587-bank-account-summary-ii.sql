# Write your MySQL query statement below
with temp as (
select u.name, sum(t.amount) as balance from users u
join transactions t
on u.account=t.account
group by u.name
)
select name, balance from temp where balance > 10000
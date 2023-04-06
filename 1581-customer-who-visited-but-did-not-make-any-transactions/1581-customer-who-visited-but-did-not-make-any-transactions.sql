# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) - count(t.visit_id) as count_no_trans from visits v
left outer join transactions t on v.visit_id = t.visit_id
group by v.customer_id
having count_no_trans > 0

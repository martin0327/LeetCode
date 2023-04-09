select id, 'Root' as type 
from tree
where p_id is null
union
select id, 'Inner' as type
from tree
where id in (select p_id from tree)
and p_id is not null
union
select id, 'Leaf' as type
from tree
where id not in (select distinct p_id from tree where p_id is not null)
and p_id is not null
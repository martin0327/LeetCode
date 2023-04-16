with
  t as (
    select
      score,
      rank() over (
        order by
          score desc
      ) as id
    from
      scores
    group by
      score
    order by
      score desc
  )
select
  s.score,
  t.id as "rank"
from
  scores s
  join t on s.score = t.score
order by
  s.score desc
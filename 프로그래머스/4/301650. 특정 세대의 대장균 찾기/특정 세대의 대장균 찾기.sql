with recursive temp(id, level) as (
    select id, 1
    from ecoli_data
    where parent_id is null
    union all
    select c.id, level + 1
    from temp p
    join ecoli_data c on p.id = c.parent_id
    where level + 1 <= 3
)
select id
from temp
where level = 3
order by id
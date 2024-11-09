with recursive temp(id, level, parent) as (
    select id, 1, 0
    from ecoli_data
    where parent_id is null
    union all
    select c.id, level + 1, p.id
    from temp p
    join ecoli_data c on p.id = c.parent_id
)

select count(*) count, p.level generation
from temp p
left join temp c on c.parent = p.id
where c.id is null
group by p.level

# select count(*) as count, level generation
# from temp
# group by level
with temp as (
    select id, length, 
    rank() over(partition by fish_type order by length desc) as r
    from fish_info
)
select f.id, fish_name, f.length
from fish_info f
join temp t on f.id = t.id and t.r = 1
join fish_name_info using (fish_type)
order by id
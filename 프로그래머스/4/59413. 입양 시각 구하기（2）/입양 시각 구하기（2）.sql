with recursive temp(hour) as (
    select 0
    union all
    select hour + 1
    from temp
    where hour < 23
)


select hour, count(animal_id) count
from animal_outs
right join temp on hour = hour(datetime)
# where 
group by 1
order by 1
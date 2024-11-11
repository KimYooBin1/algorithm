select food_type, rest_id, rest_name, favorites
from (
    select *, rank() over (partition by food_type order by favorites desc) r
    from rest_info
) a
where a.r = 1
group by 1
order by 1 desc
select count(*) fish_count, max(length) max_length, fish_type
from (
    select id, fish_type, coalesce(length, 10) length, time
    from fish_info
) a
group by fish_type
having 33 <= avg(length)
order by fish_type
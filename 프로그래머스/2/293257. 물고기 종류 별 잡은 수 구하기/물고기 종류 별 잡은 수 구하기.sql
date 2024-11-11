select count(*) fish_count, fish_name
from fish_info
join fish_name_info using (fish_type)
group by fish_name
order by 1 desc
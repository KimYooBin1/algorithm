select count(*) fish_count, month(time) month
from fish_info
group by 2
order by month
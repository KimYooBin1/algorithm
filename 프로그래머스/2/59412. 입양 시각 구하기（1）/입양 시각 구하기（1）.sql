select hour(datetime), count(*) count
from animal_outs 
where time(datetime) between "09:00" and "19:59"
group by 1
order by 1
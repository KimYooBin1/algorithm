select animal_id, i.name
from animal_ins i
join animal_outs o using (animal_id)
where o.datetime < i.datetime
order by i.datetime
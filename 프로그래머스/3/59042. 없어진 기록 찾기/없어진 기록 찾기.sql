select animal_id, o.name name
from animal_outs o
left join animal_ins i using (animal_id)
where i.name is null and o.name is not null
order by animal_id, name
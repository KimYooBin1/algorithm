select o.animal_id, o.name
from animal_outs o
join animal_ins  i using (animal_id)
order by timestampdiff(day, i.datetime, o.datetime) desc
limit 0, 2
select animal_id, o.animal_type, o.name
from animal_outs o
join animal_ins i using (animal_id)
where o.sex_upon_outcome not like "Intact%" and i.sex_upon_intake like "Intact%"
order by 1
# select count(name) count
# from animal_ins
# where name is not null

select count(a.name) count
from (select distinct name from animal_ins
where name is not null
) a
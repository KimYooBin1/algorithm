select ID, (
    select count(*)
    from ECOLI_DATA as C
    where P.ID = C.PARENT_ID
) as CHILD_COUNT
from ecoli_data as P
group by ID
order by ID
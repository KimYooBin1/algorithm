with temp as (
    select flavor, sum(total_order) total_order
    from july
    group by flavor
), temp1 as (
    select t.flavor, t.total_order + f.total_order count
    from temp t
    join first_half f on t.flavor = f.flavor
    order by 2 desc
)

select flavor
from temp1
limit 0, 3
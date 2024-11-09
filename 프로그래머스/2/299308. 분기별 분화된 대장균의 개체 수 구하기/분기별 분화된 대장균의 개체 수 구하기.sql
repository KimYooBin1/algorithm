with temp as (
    select id, substr(DIFFERENTIATION_DATE, 6, 2) m
    from ecoli_data
),
calc as (
    select id, (
        case when 1<=m and m<=3 then 1 else
        case when 4<=m and m<=6 then 2 else
        case when 7<=m and m<=9 then 3 else 4
        end end end
    ) q
    from temp
)

select concat(q, 'Q') quarter, count(*) ecoli_count
from calc
group by q
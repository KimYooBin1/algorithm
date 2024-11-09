with temp as (
    select id, month(differentiation_date) m
    from ecoli_data
),
calc as (
    select id, (
        case when 1<=m and m<=3 then 1 else
        case when m<=6 then 2 else
        case when m<=9 then 3 else 4
        end end end
    ) q
    from temp
)

select concat(q, 'Q') quarter, count(id) ecoli_count
from calc
group by quarter
order by quarter
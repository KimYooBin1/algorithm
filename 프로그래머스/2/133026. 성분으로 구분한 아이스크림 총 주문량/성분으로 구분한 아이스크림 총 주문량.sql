with temp as (
    select flavor, case when ingredient_type like "sugar%" then 1 else 0 end type
    from icecream_info
)
select case type when 1 then "sugar_based" else "fruit_based" end ingredient_type, sum(total_order) total_order
from first_half
join temp using (flavor)
group by type
order by 2 
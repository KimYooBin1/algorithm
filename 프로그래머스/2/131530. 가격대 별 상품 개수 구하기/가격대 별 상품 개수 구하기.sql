with temp as (
    select 10000 * truncate(price / 10000, 0) price_group, count(*) products
    from product
    group by 1
)

select *
from temp
order by 1
with temp as (
    select max(price) p
    from food_product
)

select product_id, product_name, product_cd, category, price
from food_product
join temp on p = price
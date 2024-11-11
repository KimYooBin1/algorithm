with temp as (
    select category, max(price) price
    from food_product
    group by category
)
select p.category, p.price max_price, product_name product_name
from food_product p
join temp t on p.category = t.category and p.price = t.price
where p.category in ("과자", "국", "김치", "식용유")
order by 2 desc
select product_id, product_name, price * amount total_sales
from food_product
join (
    select product_id, sum(amount) amount
    from food_order
    where produce_date between "2022-05-01" and "2022-05-31"
    group by product_id
) a using (product_id)
# group by product_id
order by 3 desc, product_id
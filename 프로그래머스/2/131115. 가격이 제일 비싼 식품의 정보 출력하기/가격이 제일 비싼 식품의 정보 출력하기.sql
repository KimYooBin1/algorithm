select product_id, product_name, product_cd, category, price
from food_product
group by product_id
order by price desc
limit 1
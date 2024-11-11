select product_code, price * sales_amount sales
from product
join (
    select product_id, sum(sales_amount) sales_amount
    from offline_sale
    group by product_id
) a using (product_id)
order by 2 desc , product_code
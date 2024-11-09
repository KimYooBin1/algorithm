select substr(product_code, 1, 2) category, count(*) products
from product
group by 1
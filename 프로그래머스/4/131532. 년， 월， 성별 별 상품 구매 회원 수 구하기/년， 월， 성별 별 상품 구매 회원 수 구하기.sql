select year(SALES_DATE) year, month(SALES_DATE) month, gender, count(distinct user_id) users
from online_sale
join user_info using (user_id)
where gender is not null
group by 1, 2, 3
order by 1, 2, 3
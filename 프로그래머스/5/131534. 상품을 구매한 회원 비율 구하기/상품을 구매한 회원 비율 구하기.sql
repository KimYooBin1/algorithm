with total_count as (
    select user_id
    from user_info
    where year(joined) = "2021"
), rate as (
    select year(sales_date) year, month(sales_date) month, count(distinct user_id) count_user
    from online_sale
    join total_count using (user_id)
    group by 1, 2
)

select year, month, count_user purchased_users, round((count_user / (
    select count(user_id)
    from total_count
)), 1) puchased_ratio
from rate
order by 1, 2
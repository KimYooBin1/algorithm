with temp as (
    select distinct car_id, 1 c
    from car_rental_company_rental_history
    where "2022-10-16" between start_date and end_date
)
select distinct car_id, case when c is null then "대여 가능" else "대여중" end availabilty
from car_rental_company_rental_history
left join temp using (car_id)
order by car_id desc

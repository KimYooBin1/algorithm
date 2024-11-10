with temp as (
    select car_id, car_type, daily_fee * 30 fee
    from car_rental_company_car
    where car_type in ("세단", "SUV") and car_id not in (
        select distinct car_id
        from car_rental_company_rental_history
        where
        ('2022-11-01' between start_date and end_date)
        or ('2022-11-30' between start_date and end_date)
        or ('2022-11-01' < start_date and end_date < '2022-11-30')
    )
)

select car_id, car_type, floor(fee * (100-discount_rate)/100) fee
from temp
join car_rental_company_discount_plan using (car_type)
where duration_type like "30일 이상" and (floor(fee * (100-discount_rate)/100) between 500000 and 1999999)
order by fee desc, car_type, car_id desc

# select car_id, start_date, end_date
# from car_rental_company_rental_history
# where car_id = 27

# select *
# from temp
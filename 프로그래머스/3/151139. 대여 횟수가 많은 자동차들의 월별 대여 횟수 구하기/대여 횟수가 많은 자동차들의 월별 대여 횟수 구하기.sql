with rental_count as (
    select car_id
    from car_rental_company_rental_history
    where start_date between "2022-08-01" and "2022-10-31"
    group by car_id
    having 5 <= count(*)
)

select month(start_date) month, car_id, count(*) records
from car_rental_company_rental_history
join rental_count using (car_id)
where start_date between "2022-08-01" and "2022-10-31"
group by 1, 2
order by 1, 2 desc

# select distinct car_id
# from car_rental_company_rental_history
# order by 1
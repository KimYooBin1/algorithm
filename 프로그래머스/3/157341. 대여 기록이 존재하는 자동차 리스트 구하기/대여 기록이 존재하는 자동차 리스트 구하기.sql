select distinct car_id
from car_rental_company_car
join car_rental_company_rental_history using (car_id)
where car_type = "세단" and 10 <= month(start_date)
order by car_id desc
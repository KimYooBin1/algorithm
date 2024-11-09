select car_id, round(avg(timestampdiff(day, start_date, end_date + interval 1 day)), 1) average_duration
from car_rental_company_rental_history
group by car_id
having 7 <= average_duration
order by 2 desc, car_id desc

# select timestampdiff(day, '2012-01-01', '2012-01-01' + interval 1 day) as day;
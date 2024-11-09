select history_id, car_id, date_format(start_date, '%Y-%m-%d') start_date, date_format(end_date, '%Y-%m-%d') end_date, 
case
    when 30 <= timestampdiff(day, start_date, end_date + interval 1 day) then "장기 대여"
    else "단기 대여"
end
rent_type
from car_rental_company_rental_history
where start_date between '2022-09-01' and '2022-09-30'
order by history_id desc
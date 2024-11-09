with temp as (
    select convert(substr(duration_type, 1, instr(duration_type, "일") - 1), signed) as duration , convert(discount_rate, signed) rate
    from car_rental_company_discount_plan
    where car_type = "트럭"
    order by duration
)

select history_id,ceiling(daily_fee * (timestampdiff(day, start_date, end_date + interval 1 day) * ((100 - max(coalesce(rate, 0)))/100))) fee
from car_rental_company_car
join car_rental_company_rental_history using (car_id)
left join temp on duration <= (timestampdiff(day, start_date, end_date + interval 1 day))
where car_type = "트럭"
group by history_id
order by fee desc, history_id desc


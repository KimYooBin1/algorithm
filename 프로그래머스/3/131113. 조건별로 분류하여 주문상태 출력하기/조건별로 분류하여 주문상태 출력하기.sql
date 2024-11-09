select order_id, product_id, date_format(out_date, "%Y-%m-%d") out_date, (
    case 
        when out_date is null then "출고미정" else
        case when out_date <= '2022-05-01' then "출고완료"
        else "출고대기" end
    end
)출고여부
from food_order
# where
order by order_id
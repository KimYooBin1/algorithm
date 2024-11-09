with temp as (
    select id, PERCENT_RANK() over (order by size_of_colony desc) rate
    from ecoli_data
)
select id, (
    case when 0 <= rate and rate < 0.25 then "CRITICAL" else 
        case when rate < 0.5 then "HIGH" else
            case when rate < 0.75 then "MEDIUM" else "LOW"
            end
        end
    end
) colony_name
from ecoli_data
join temp using (id)
order by id;
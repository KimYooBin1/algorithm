with temp as (
    select id, RANK() over (order by size_of_colony desc) r, (select count(*) from ecoli_data) c
    from ecoli_data
),
rating as (
    select id, r / c rate
    from temp
)

select id, (
    case when 0 < rate and rate <= 0.25 then "CRITICAL" else 
        case when rate <= 0.5 then "HIGH" else
            case when rate <= 0.75 then "MEDIUM" else "LOW"
            end
        end
    end
) colony_name
from ecoli_data
join rating using (id)
order by id;
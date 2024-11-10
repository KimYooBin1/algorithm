with temp as (
    select year(differentiation_date) year, max(size_of_colony) m
    from ecoli_data
    group by year
)

select year(differentiation_date) year, m - size_of_colony year_dev, id
from ecoli_data
join temp on year = year(differentiation_date)
order by year, year_dev 
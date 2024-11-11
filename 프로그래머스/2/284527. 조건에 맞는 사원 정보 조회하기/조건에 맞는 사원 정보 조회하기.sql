with temp as (
    select emp_no, year, sum(score) score
    from hr_grade
    where year = 2022
    group by 1, 2
    order by 3 desc
    limit 1
), temp2 as (
    select score, emp_no, emp_name, position, email
    from hr_employees
    join temp using (emp_no)
)
select *
from temp2
with temp as (
    select emp_no, emp_name, 
    case when 96 <= avg(score) then 'S' else
        case when 90 <= avg(score) then 'A' else
            case when 80 <= avg(score) then 'B' else 'C'
            end
        end
    end grade,
    case when 96 <= avg(score) then 0.2 else
        case when 90 <= avg(score) then 0.15 else
            case when 80 <= avg(score) then 0.1 else 0
            end
        end
    end bonus,
    sal
    from hr_employees
    join hr_grade using (emp_no)
    group by 1, 2
), temp2 as (
    select emp_no, emp_name, grade, sal * bonus bonus
    from temp
)
select *
from temp2
order by 1
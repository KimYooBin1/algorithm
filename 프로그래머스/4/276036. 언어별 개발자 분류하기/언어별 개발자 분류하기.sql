with temp as (
    select (
        case when exists (select code from skillcodes where name like "Python" and code & skill_code) and exists (select code from skillcodes where category = "Front End" and code & skill_code) then 'A' else
        case when exists (select 1 from skillcodes where name = "C#" and code & skill_code) then 'B' else
        case when exists (select 1 from skillcodes where category = 'Front End' and code & skill_code) then 'C' end
        end
        end
       ) grade, id, email
    from developers
)
select *
from temp
where grade is not null
order by 1, 2
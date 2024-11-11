select id, email, first_name, last_name
from developers
where exists (
    select 1
    from skillcodes
    where category = "Front End" and skill_code & code
)
order by id
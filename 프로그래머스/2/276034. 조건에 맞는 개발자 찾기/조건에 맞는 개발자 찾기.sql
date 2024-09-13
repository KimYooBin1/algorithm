-- 코드를 작성해주세요
select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS
where skill_code &(select sum(code) from SKILLCODES where name in ("Python", "C#"))
order by ID
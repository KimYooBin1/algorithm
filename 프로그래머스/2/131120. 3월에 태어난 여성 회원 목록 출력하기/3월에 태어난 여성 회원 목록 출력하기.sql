-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(date_of_birth, '%Y-%m-%d') as DATE_OF_BIRTH
from member_profile
where tlno is not null and date_format(date_of_birth, '%m') = 03 and gender = 'W'
order by member_id asc
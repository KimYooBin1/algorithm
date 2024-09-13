-- 코드를 입력하세요
SELECT count(*)
from user_info
where SUBSTR(JOINED, 1, 4) = "2021"
and AGE between 20 and 29
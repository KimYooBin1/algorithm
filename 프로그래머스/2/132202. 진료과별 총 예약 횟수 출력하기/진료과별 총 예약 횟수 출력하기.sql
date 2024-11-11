select MCDP_CD 진료과코드, count(*) 5월예약건수
from appointment
where apnt_ymd between '2022-05-01' and '2022-05-31'
group by MCDP_CD
order by 2, 1
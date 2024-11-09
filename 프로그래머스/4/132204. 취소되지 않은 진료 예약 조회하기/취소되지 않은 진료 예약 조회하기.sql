select apnt_no, pt_name, pt_no, a.mcdp_cd, dr_name, apnt_ymd 
from appointment a
join doctor d on d.dr_id = a.mddr_id
join patient using (pt_no)
where 
    a.mcdp_cd = "CS" 
        and 
    date_format(apnt_ymd, '%Y-%m-%d') = "2022-04-13" 
        and     
    apnt_cncl_yn = 'N'
order by apnt_ymd
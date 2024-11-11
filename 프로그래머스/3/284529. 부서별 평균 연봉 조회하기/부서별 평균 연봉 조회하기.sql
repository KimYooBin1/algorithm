select dept_id, dept_name_en, round(avg(sal), 0) avg_sal
from hr_employees
join hr_department using (dept_id)
group by 1
order by 3 desc
select year(YM) year, round(avg(pm_val1), 2) pm10, round(avg(pm_val2), 2) "pm2.5"
from air_pollution
where location2 = "수원"
group by year
order by year
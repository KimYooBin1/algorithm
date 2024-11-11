select route, concat(round(sum(d_between_dist), 1), "km") total_distance, concat(round(avg(d_between_dist), 2), "km") average_distance
from subway_distance
group by 1
order by sum(d_between_dist) desc
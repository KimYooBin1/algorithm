select user_id, nickname, sum(price) total_sales
from used_goods_user
join used_goods_board on user_id = writer_id
where status = "DONE"
group by user_id
having 700000 <= sum(price)
order by 3
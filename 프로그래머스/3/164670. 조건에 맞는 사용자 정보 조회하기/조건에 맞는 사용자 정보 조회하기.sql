select user_id, nickname, concat(city," ", street_address1," ", street_address2)전체주소, concat(substr(tlno,1,3),"-",substr(tlno,4,4),"-",substr(tlno, 8, 4))전화번호
from used_goods_board
join used_goods_user on user_id = writer_id
group by user_id
having 3 <= count(board_id)
order by user_id desc
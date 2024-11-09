with temp as (
    select board_id
    from used_goods_board
    order by views desc
    limit 1
)
select concat("/home/grep/src/",board_id, "/", file_id, file_name, file_ext) as file_path
from used_goods_file
join temp using (board_id)
order by file_id desc

# select board_id, views
# from used_goods_board
# order by views desc
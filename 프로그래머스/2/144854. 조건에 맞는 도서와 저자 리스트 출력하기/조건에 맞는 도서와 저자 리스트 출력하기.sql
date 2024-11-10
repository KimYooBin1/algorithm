select book_id, author_name, date_format(published_date, "%Y-%m-%d") published_date
from book
join author using (author_id)
where category = "경제"
order by published_date
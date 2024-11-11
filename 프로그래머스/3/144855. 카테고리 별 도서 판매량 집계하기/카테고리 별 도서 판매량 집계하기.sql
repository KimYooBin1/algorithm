# select category, book_id, count(*)
# from book
# where published_date
# group by 1, 2

with temp as (
    select book_id, sum(sales) total_sales
    from book_sales
    where sales_date between "2022-01-01" and "2022-01-31"
    group by 1
)

select category, sum(total_sales) total_sales
from temp
join book using (book_id)
group by 1
order by 1

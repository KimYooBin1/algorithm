with temp as (
    select book_id, sum(sales) sales
    from book_sales
    where sales_date between "2022-01-01" and "2022-01-31"
    group by 1
), temp1 as (
    select author_id, category, sales * price total_sales
    from book
    join temp using (book_id)
)

select author_id, author_name, category, sum(total_sales)
from author
join temp1 using (author_id)
group by 1, 3
order by 1, 3 desc

# select *
# from temp1
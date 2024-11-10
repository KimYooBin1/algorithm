with temp as (
    select member_id, count(*) c
    from rest_review
    group by member_id
    order by c desc
    limit 1
), review as (
    select review_text, review_date, member_id
    from temp
    join rest_review using (member_id)
)
select member_name, review_text, date_format(review_date, '%Y-%m-%d') review_date
from review
join member_profile using (member_id)
order by 3, 2

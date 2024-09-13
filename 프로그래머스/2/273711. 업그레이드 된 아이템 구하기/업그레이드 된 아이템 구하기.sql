-- 코드를 작성해주세요
select ITEM_ID, ITEM_NAME, RARITY
from ITEM_INFO as N
where N.ITEM_ID in (
    select T.ITEM_ID
    from ITEM_INFO as I
    join ITEM_TREE as T
    on I.ITEM_ID = T.PARENT_ITEM_ID
    where I.RARITY = "RARE"
)
order by ITEM_ID desc;
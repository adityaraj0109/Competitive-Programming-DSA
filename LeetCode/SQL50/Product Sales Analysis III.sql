with temp as (
select *, rank() over(partition by product_id order by year) as firstyear
from Sales 
)

select product_id, year as first_year, quantity, price
from temp
where firstyear=1
with temp as(
    select visited_on, sum(amount) as total
    from Customer
    group by visited_on
),

cte as(select visited_on, 
sum(total) over(order by visited_on rows between 6 preceding and current row) as amount,
round(avg(total) over(order by visited_on rows between 6 preceding and current row),2) 
as average_amount
from temp)

select * from cte
where visited_on>=
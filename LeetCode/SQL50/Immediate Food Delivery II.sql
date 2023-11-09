with temp as(
    select *, rank() over(partition by customer_id order by order_date) as ranking
    from Delivery
)

select round(sum(case when order_date=customer_pref_delivery_date then 1 else 0 end)*100/count(distinct customer_id),2) as immediate_percentage 
from temp
where ranking=1
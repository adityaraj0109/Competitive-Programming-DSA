with ct as(
    select p.product_id ,p.product_name, t.order_date, t.unit from Orders t
    left join Products p
    on p.product_id=t.product_id
    where t.order_date between '2020-02-01' and '2020-02-29'
)

select product_name, sum(unit) as unit from ct
group by product_id
having sum(unit)>=100
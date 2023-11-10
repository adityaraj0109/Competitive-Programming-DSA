select customer_id
from (select *, count(*) as cnt from Customer 
group by customer_id, product_key) temp
group by customer_id
having count(*) = (select count(*) from Product)
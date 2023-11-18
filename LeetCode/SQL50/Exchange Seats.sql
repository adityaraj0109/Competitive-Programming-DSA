with temp as(select *,lead(student,1) over() as next, lag(student,1) over() as prev
from Seat)

select id, (case when mod(id,2)=1 and next is null then student when mod(id,2)=1 then next else prev end) as student
from temp
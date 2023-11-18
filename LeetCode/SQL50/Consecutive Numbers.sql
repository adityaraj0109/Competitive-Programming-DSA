select distinct num as ConsecutiveNums from (select *, lead(num,1) over() as next,
lead(num,2) over() as nexttonext
from Logs) temp
where num=next and num=nexttonext
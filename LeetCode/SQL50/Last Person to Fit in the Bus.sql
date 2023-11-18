with temp as(
  select *, sum(weight) over(order by turn) as total
  from Queue 
)

select person_name from temp
where turn=(
  select max(turn) from temp
  where total<=1000
)
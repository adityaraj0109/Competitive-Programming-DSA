with temp as (
    select m.*, u.name, mov.title from MovieRating m
    inner join Users u
    on m.user_id=u.user_id
    inner join Movies mov
    on m.movie_id=mov.movie_id
)

(select name as results from temp
group by user_id
order by count(*) desc, name 
limit 1)
union all
(select title as results from temp
where created_at between '2020-02-01' and '2020-02-29'
group by movie_id
order by avg(rating) desc, title
limit 1)
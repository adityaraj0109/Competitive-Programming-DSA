with temp as (
    select player_id, event_date, lead(event_date,1) over(partition by player_id order by event_date) as next,
    date_add(event_date, interval 1 day) as dateplusone
    from Activity
)
,
t as(
    select *, min(event_date) as first
    from temp
    group by player_id
)

select round(sum(newcol)/count(*),2) as fraction from
(select *, case when next=dateplusone then 1 else 0 end as newcol from t) d
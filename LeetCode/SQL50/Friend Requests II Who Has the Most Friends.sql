with temp as(
    select requester_id as id, accepter_id as frnd from RequestAccepted
    union
    select accepter_id as id, requester_id as frnd from RequestAccepted
)

select id, count(*) as num from temp
group by id
order by count(*) desc
limit 1
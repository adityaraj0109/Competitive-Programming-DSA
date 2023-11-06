with temp as (
  select * from Students 
  cross join Subjects 
)

select t.student_id, t.student_name, t.subject_name, 
sum(case when e.student_id is null then 0 else 1 end) 
as attended_exams from temp t
left join Examinations e
on t.student_id=e.student_id and t.subject_name=e.subject_name
group by t.student_id, t.student_name, t.subject_name
order by t.student_id, t.subject_name
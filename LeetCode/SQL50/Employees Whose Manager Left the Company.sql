with temp as (
    select * from Employees 
    where salary<30000 and manager_id is not null
)

select t.employee_id from temp t
left join Employees e
on t.manager_id=e.employee_id
where e.salary is null
order by t.employee_id
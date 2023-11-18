with temp as(select departmentId, name, salary, dense_rank() over(partition by departmentId order by salary desc) as ranking from Employee) 

select d.name as Department, t.name as Employee, t.salary as Salary from temp t
inner join Department d
on t.departmentId=d.id
where t.ranking<=3
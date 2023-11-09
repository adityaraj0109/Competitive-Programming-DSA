select p.project_id, Round(sum(e.experience_years)/count(*),2) as average_years from Project p
inner join Employee e
on p.employee_id=e.employee_id
group by p.project_id
select e1.employee_id, e1.name, count(*) as reports_count, round(sum(e2.age)/count(*)) as average_age
from Employees e1, Employees e2
where e1.employee_id= e2.reports_to
group by e1.employee_id
order by e1.employee_id
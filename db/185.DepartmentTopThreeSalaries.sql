# Write your MySQL query statement below
# set output
select de.Name as Department, em.Name as Employee,em.Salary
from Employee em 
# remove interference
join Department de on  em.DepartmentId=de.Id
# two filter requires, highest salary for each department
#filter the res with having or  make it as requires with where
#sub query -> (like if control) and "(subquery) indicates a subquery that returns a single value; that is, a scalar subquery." 
having 3 >
(
    select count(distinct e2.Salary)
    from Employee e2
    where e2.Salary > em.Salary and
      em.DepartmentId = e2.DepartmentId
)

# Write your MySQL query statement below
# set output
select de.Name as Department, em.Name as Employee,em.Salary
from Employee em 
# remove interference
join Department de on  em.DepartmentId=de.Id
# two filter requires, highest salary for each department
where (em.DepartmentId, em.Salary) in
(SELECT
    DepartmentId, MAX(Salary)
FROM
    Employee 
GROUP BY DepartmentId)

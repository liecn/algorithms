# Write your MySQL query statement below
# Select E.Name as Employee from Employee E,Employee E1 
# where E.ManagerId=E1.Id and E.Salary>E1.Salary
SELECT e1.Name as Employee FROM Employee e1
JOIN Employee e2
on e1.ManagerId=e2.Id
where e1.Salary> e2.Salary and e1.ManagerId=e2.Id

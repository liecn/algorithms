# Write your MySQL query statement below
# the first SELECT can handle the null situation.
SELECT 
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) SecondHighestSalary

# Write your MySQL query statement below
SELECT Email FROM Person
GROUP BY Email
Having count(*)>1

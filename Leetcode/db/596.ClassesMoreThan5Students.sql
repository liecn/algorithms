# Write your MySQL query statement below
select class from courses 
group by class
#Deduplication with distinct(can be done directly or make a new table)
having count(distinct (student))>4

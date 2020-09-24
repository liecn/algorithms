# Write your MySQL query statement below
select L.Num as ConsecutiveNums from
(select Distinct l1.Num
from Logs l1 
left join Logs l2 on l1.id=l2.id-1
left join Logs l3 on l2.id=l3.id-1
where l1.Num=l2.Num and l2.Num=l3.Num) L


# Select DISTINCT l1.Num as ConsecutiveNums from Logs l1, Logs l2, Logs l3 
# where l1.Id=l2.Id-1 and l2.Id=l3.Id-1 
# and l1.Num=l2.Num and l2.Num=l3.Num

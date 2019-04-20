# Write your MySQL query statement below
DELETE p1 FROM Person p1, Person p2 where p1.Email = p2.Email and p1.Id > p2.I
d
# Write your MySQL query statement below
DELETE p1 FROM Person p1 join Person p2 on p1.Email = p2.Email where p1.Id > p2.Id


# Write your MySQL query statement below
select distinct(s1.id), s1.visit_date,s1.people 
from stadium s1, stadium s2, stadium s3
where 
#note that the visit_date could not be continuous
(
	  (s1.id - s2.id = 1 and s1.id - s3.id = 2 and s2.id - s3.id =1)  -- s3, s2, s1
    or
    (s1.id - s2.id = 1 and s3.id - s2.id = 2 and s3.id - s1.id =1) -- s2, s1, s3
    or
    (s3.id - s2.id = 1 and s2.id - s1.id =1 and s3.id - s1.id = 2) -- s1, s2, s3
)
and s1.people>=100
and s2.people>=100
and s3.people>=100
order by s1.id


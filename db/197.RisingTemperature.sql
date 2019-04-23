# Write your MySQL query statement below
select w1.Id from Weather w1 join Weather w2
on 
#TO_DAYS() returns the number of days between from year 0 to date DATE
#DATEDIFF(d1,d2) returns the diff days between d1,d2
TO_DAYS(w1.RecordDate)-TO_DAYS(w2.RecordDate) = 1
where 
w1.Temperature>w2.Temperature

# select w1.Id from Weather w1, Weather w2
# where 
# #TO_DAYS() returns the number of days between from year 0 to date DATE
# #DATEDIFF(d1,d2) returns the diff days between d1,d2
# DATEDIFF(w1.RecordDate,w2.RecordDate) = 1
# and
# w1.Temperature>w2.Temperature

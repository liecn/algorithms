# Write your MySQL query statement below
# UPDATE salary
# SET sex = if(sex = 'm', 'f', 'm')
#a^a=0,interesting solution by someone
update salary set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex));

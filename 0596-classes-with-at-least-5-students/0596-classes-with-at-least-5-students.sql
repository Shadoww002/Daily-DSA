# Write your MySQL query statement below
-- Classes More Than 5 Students

select class 
from Courses
group by class 
having count(*) >= 5 ;

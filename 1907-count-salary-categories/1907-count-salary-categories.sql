# Write your MySQL query statement below

-- select category , count(*) as accounts_count
-- from(
--     select income , 
--         case 
--             when income < 2000 then "Low Salary"
--             when income between 2000 and 5000 then "Average Salary"
--             else "High Salary"
--         end as category
--     from Accounts 
-- ) as t 
-- group by category ;


SELECT 'Low Salary' AS category, COUNT(*) AS accounts_count
FROM Accounts WHERE income < 20000
UNION ALL
SELECT 'Average Salary', COUNT(*)
FROM Accounts WHERE income BETWEEN 20000 AND 50000
UNION ALL
SELECT 'High Salary', COUNT(*)
FROM Accounts WHERE income > 50000;
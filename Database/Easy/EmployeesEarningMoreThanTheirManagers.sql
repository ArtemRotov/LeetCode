/*
181. Employees Earning More Than Their Managers

Table: Employee
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of an employee, their name, salary,
and the ID of their manager.
 

Write an SQL query to find the employees who earn more than their managers.

Return the result table in any order.
*/

# Write your MySQL query statement below

SELECT E1.name AS Employee FROM employee E1
JOIN employee E2 ON E2.id = E1.managerId
WHERE E1.salary > E2.salary

# way 2 - bad
# SELECT E.name AS Employee FROM Employee E
# WHERE E.salary > (SELECT M.salary FROM Employee M WHERE E.managerId = M.id)



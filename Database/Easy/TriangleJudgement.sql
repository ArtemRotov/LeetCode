/*
610. Triangle Judgement

Table: Triangle
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
(x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.

Write an SQL query to report for every three line segments whether they can form a triangle.
Return the result table in any order.
The query result format is in the following example
*/


# Write your MySQL query statement below

#1
SELECT *, IF(x+y>z AND x+z>y AND y+z>x, "Yes", "No") AS triangle FROM Triangle

#2
SELECT *, (CASE WHEN x + y > z and y + z > x and x + z > y THEN 'Yes' Else 'No' END) AS triangle FROM Triangle

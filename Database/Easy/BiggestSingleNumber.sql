/*
619. Biggest Single Number

Table: MyNumbers

+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
There is no primary key for this table. It may contain duplicates.
Each row of this table contains an integer.
 

A single number is a number that appeared only once in the MyNumbers table.

Write an SQL query to report the largest single number. If there is no single number, report null.

The query result format is in the following example.
*/

# Write your MySQL query statement below

SELECT IF(COUNT(*) = 1, num, NULL) as NUM from MyNumbers 
GROUP BY num 
ORDER BY count(*), num DESC LIMIT 1

# SELECT num FROM MyNumbers
# GROUP BY num
# HAVING COUNT(*) = 1
# ORDER BY num DESC LIMIT 1

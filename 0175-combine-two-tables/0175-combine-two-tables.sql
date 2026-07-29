# Write your MySQL query statement below
SELECT
    a.firstName,
    a.lastName,
    s.city,
    s.state
FROM Person a
LEFT JOIN Address s
ON a.personId = s.personId;
# Write your MySQL query statement below
SELECT e.name AS Customers
FROM Customers e
LEFT JOIN Orders d
ON d.customerId = e.id
WHERE d.customerId IS NULL;
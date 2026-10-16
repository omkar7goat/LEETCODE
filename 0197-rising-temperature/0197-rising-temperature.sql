# Write your MySQL query statement below

SELECT w.id AS Id
FROM Weather w
JOIN Weather ws
  ON DATEDIFF(w.recordDate, ws.recordDate) = 1
WHERE w.temperature > ws.temperature;
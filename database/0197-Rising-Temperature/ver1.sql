# Write your MySQL query statement below
SELECT
  Weather.Id
FROM
  Weather JOIN Weather AS W ON
    DATEDIFF(Weather.RecordDate, W.RecordDate) = 1
WHERE
  Weather.Temperature > W.Temperature;

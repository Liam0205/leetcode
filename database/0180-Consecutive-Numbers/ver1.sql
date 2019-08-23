# Write your MySQL query statement below
SELECT DISTINCT
  l1.Num AS ConsecutiveNums
FROM
  Logs AS l1 JOIN
  Logs AS l2 JOIN
  Logs AS l3 ON
    l1.Id + 1 = l2.Id AND l2.Id + 1 = l3.Id
WHERE
  l1.Num = l2.Num AND
  l2.Num = l3.Num;

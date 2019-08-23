# Write your MySQL query statement below
DELETE
  p1
FROM
  Person AS p1 JOIN Person AS p2 ON
    p1.Email = p2.Email
WHERE
  p1.Id > p2.Id;

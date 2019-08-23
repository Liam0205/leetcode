# Write your MySQL query statement below
DELETE
FROM
  Person
WHERE
  Id NOT IN (
    SELECT
      p.id
    FROM
      (
        SELECT
          MIN(Id) AS id
        FROM
          Person
        GROUP BY
          Email
      ) AS p
  );

# Write your MySQL query statement below
SELECT
  (
    CASE
      WHEN MOD(id, 2) != 0 AND seat_counts.counts != id THEN id + 1
      WHEN MOD(id, 2) != 0 AND seat_counts.counts = id THEN id
      ELSE id - 1
    END
  ) AS id,
  student
FROM
  seat CROSS JOIN (
    SELECT
      COUNT(*) AS counts
    FROM
      seat
  ) AS seat_counts
ORDER BY
  id ASC;

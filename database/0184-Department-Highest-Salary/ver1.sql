# Write your MySQL query statement below
SELECT
  t2.Department,
  Employee.Name AS Employee,
  Employee.Salary
FROM
  (
    SELECT
      Department.Name AS Department,
      t1.DepartmentId AS DepartmentId,
      t1.s AS Salary
    FROM
      (
        SELECT
          DepartmentId,
          MAX(Salary) AS s
        FROM
          Employee
        GROUP BY
          DepartmentId
      ) AS t1 JOIN Department ON
        t1.DepartmentId = Department.Id
  ) AS t2 JOIN Employee ON
    t2.Salary = Employee.Salary AND
    t2.DepartmentId = Employee.DepartmentId;

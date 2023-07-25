SELECT b.name AS Employee FROM Employee AS a JOIN Employee AS b ON a.id = b.managerId AND a.salary < b.salary;

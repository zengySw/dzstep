-- 1 ----------------------
SELECT [Name]
FROM Departments
WHERE Building = (
    SELECT Building
    FROM Departments
    WHERE [Name] = 'Cardiology'
) AND [Name] != 'Cardiology';

-- 2 ----------------------
SELECT [Name]
FROM Departments
WHERE Building IN (
    SELECT Building
    FROM Departments
    WHERE [Name] IN ('Gastroenterology', 'General Surgery')
) AND [Name] NOT IN ('Gastroenterology', 'General Surgery');

-- 3 ----------------------
SELECT [Name]
FROM Departments
WHERE Id = (
    SELECT TOP 1 DepartmentId
    FROM Donations
    GROUP BY DepartmentId
    ORDER BY SUM(Amount) ASC
);

-- 4 ----------------------
SELECT Surname
FROM Doctors
WHERE Salary > (
    SELECT Salary
    FROM Doctors
    WHERE [Name] = 'Thomas' AND Surname = 'Gerada'
);

-- 5 ----------------------
SELECT [Name]
FROM Wards
WHERE Places > (
    SELECT AVG(Places)
    FROM Wards
    WHERE DepartmentId = (
        SELECT Id
        FROM Departments
        WHERE [Name] = 'Microbiology'
    )
);

-- 6 ----------------------
SELECT ([Name] + ' ' + Surname) AS [FullName]
FROM Doctors
WHERE (Salary + Premium) > (
    SELECT (Salary + Premium) + 100
    FROM Doctors
    WHERE [Name] = 'Anthony' AND Surname = 'Davis'
);

-- 7 ----------------------
SELECT [Name]
FROM Departments
WHERE Id IN (
    SELECT DepartmentId
    FROM Wards
    WHERE Id IN (
        SELECT WardId
        FROM DoctorsExaminations
        WHERE DoctorId = (
            SELECT Id
            FROM Doctors
            WHERE [Name] = 'Joshua' AND Surname = 'Bell'
        )
    )
);

-- 8 ----------------------
SELECT [Name]
FROM Sponsors
WHERE Id NOT IN (
    SELECT SponsorId
    FROM Donations
    WHERE DepartmentId IN (
        SELECT Id
        FROM Departments
        WHERE [Name] IN ('Neurology', 'Oncology')
    )
);

-- 9 ----------------------
SELECT DISTINCT Surname
FROM Doctors
WHERE Id IN (
    SELECT DoctorId
    FROM DoctorsExaminations
    WHERE StartTime >= '12:00:00' AND StartTime <= '15:00:00'
);
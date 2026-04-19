-- 1 --- СОЗДАНИЕ ТАБЛИЦ (DDL) ----------------------

CREATE TABLE [Sponsors] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

CREATE TABLE [Examinations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

CREATE TABLE [Specializations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

CREATE TABLE [Departments] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Building] INT NOT NULL CHECK ([Building] BETWEEN 1 AND 5),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

CREATE TABLE [Doctors] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(MAX) NOT NULL CHECK ([Name] <> ''),
    [Surname] NVARCHAR(MAX) NOT NULL CHECK ([Surname] <> ''),
    [Salary] MONEY NOT NULL CHECK ([Salary] > 0),
    [Premium] MONEY NOT NULL DEFAULT 0 CHECK ([Premium] >= 0)
);

CREATE TABLE [Wards] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(20) NOT NULL UNIQUE CHECK ([Name] <> ''),
    [Places] INT NOT NULL CHECK ([Places] >= 1),
    [DepartmentId] INT NOT NULL FOREIGN KEY REFERENCES [Departments]([Id])
);

CREATE TABLE [Donations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Amount] MONEY NOT NULL CHECK ([Amount] > 0),
    [Date] DATE NOT NULL DEFAULT GETDATE() CHECK ([Date] <= GETDATE()),
    [DepartmentId] INT NOT NULL FOREIGN KEY REFERENCES [Departments]([Id]),
    [SponsorId] INT NOT NULL FOREIGN KEY REFERENCES [Sponsors]([Id])
);

CREATE TABLE [DoctorsExaminations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [StartTime] TIME NOT NULL CHECK ([StartTime] BETWEEN '08:00:00' AND '18:00:00'),
    [EndTime] TIME NOT NULL,
    [DoctorId] INT NOT NULL FOREIGN KEY REFERENCES [Doctors]([Id]),
    [ExaminationId] INT NOT NULL FOREIGN KEY REFERENCES [Examinations]([Id]),
    [WardId] INT NOT NULL FOREIGN KEY REFERENCES [Wards]([Id]),
    CONSTRAINT CK_DoctorsExaminations_Time CHECK ([EndTime] > [StartTime])
);

CREATE TABLE [DoctorsSpecializations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [DoctorId] INT NOT NULL FOREIGN KEY REFERENCES [Doctors]([Id]),
    [SpecializationId] INT NOT NULL FOREIGN KEY REFERENCES [Specializations]([Id])
);

CREATE TABLE [Vacations] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [StartDate] DATE NOT NULL,
    [EndDate] DATE NOT NULL,
    [DoctorId] INT NOT NULL FOREIGN KEY REFERENCES [Doctors]([Id]),
    CONSTRAINT CK_Vacations_Dates CHECK ([EndDate] > [StartDate])
);

-- 2 --- ЗАПОЛНЕНИЕ ДАННЫМИ (INSERT) ----------------

INSERT INTO [Sponsors] ([Name]) VALUES ('Charity Health'), ('Global Aid');

INSERT INTO [Examinations] ([Name]) VALUES ('MRI Scan'), ('Blood Test');

INSERT INTO [Specializations] ([Name]) VALUES ('Therapist'), ('Surgeon');

INSERT INTO [Departments] ([Building], [Name]) VALUES (1, 'Cardiology'), (2, 'Neurology');

INSERT INTO [Doctors] ([Name], [Surname], [Salary], [Premium]) 
VALUES ('Thomas', 'Gerada', 5000, 500), ('Anthony', 'Davis', 4500, 300);

INSERT INTO [Wards] ([Name], [Places], [DepartmentId]) 
VALUES ('Ward A1', 4, 1), ('Ward B2', 2, 2);

INSERT INTO [Donations] ([Amount], [Date], [DepartmentId], [SponsorId]) 
VALUES (10000, '2026-04-10', 1, 1), (5000, '2026-04-15', 2, 2);

INSERT INTO [DoctorsExaminations] ([StartTime], [EndTime], [DoctorId], [ExaminationId], [WardId])
VALUES ('09:00:00', '10:00:00', 1, 1, 1), ('14:00:00', '14:30:00', 2, 2, 2);

INSERT INTO [DoctorsSpecializations] ([DoctorId], [SpecializationId]) 
VALUES (1, 2), (2, 1);

INSERT INTO [Vacations] ([StartDate], [EndDate], [DoctorId]) 
VALUES ('2026-06-01', '2026-06-15', 1), ('2026-07-10', '2026-07-25', 2);
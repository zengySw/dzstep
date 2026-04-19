-- Создание таблицы Факультеты
CREATE TABLE [Faculties] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

-- Создание таблицы Кафедры
CREATE TABLE [Departments] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Financing] MONEY NOT NULL DEFAULT 0 CHECK ([Financing] >= 0),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> ''),
    [FacultyId] INT NOT NULL,
    CONSTRAINT FK_Departments_Faculties FOREIGN KEY ([FacultyId]) REFERENCES [Faculties]([Id])
);

-- Создание таблицы Группы
CREATE TABLE [Groups] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(10) NOT NULL UNIQUE CHECK ([Name] <> ''),
    [Year] INT NOT NULL CHECK ([Year] BETWEEN 1 AND 5),
    [DepartmentId] INT NOT NULL,
    CONSTRAINT FK_Groups_Departments FOREIGN KEY ([DepartmentId]) REFERENCES [Departments]([Id])
);

-- Создание таблицы Дисциплины
CREATE TABLE [Subjects] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(100) NOT NULL UNIQUE CHECK ([Name] <> '')
);

-- Создание таблицы Преподаватели
CREATE TABLE [Teachers] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [Name] NVARCHAR(MAX) NOT NULL CHECK ([Name] <> ''),
    [Surname] NVARCHAR(MAX) NOT NULL CHECK ([Surname] <> ''),
    [Salary] MONEY NOT NULL CHECK ([Salary] > 0)
);

-- Создание таблицы Лекции
CREATE TABLE [Lectures] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [DayOfWeek] INT NOT NULL CHECK ([DayOfWeek] BETWEEN 1 AND 7),
    [LectureRoom] NVARCHAR(MAX) NOT NULL CHECK ([LectureRoom] <> ''),
    [SubjectId] INT NOT NULL,
    [TeacherId] INT NOT NULL,
    CONSTRAINT FK_Lectures_Subjects FOREIGN KEY ([SubjectId]) REFERENCES [Subjects]([Id]),
    CONSTRAINT FK_Lectures_Teachers FOREIGN KEY ([TeacherId]) REFERENCES [Teachers]([Id])
);

-- Создание таблицы Группы и лекции (Связующая таблица)
CREATE TABLE [GroupsLectures] (
    [Id] INT PRIMARY KEY IDENTITY(1,1),
    [GroupId] INT NOT NULL,
    [LectureId] INT NOT NULL,
    CONSTRAINT FK_GroupsLectures_Groups FOREIGN KEY ([GroupId]) REFERENCES [Groups]([Id]),
    CONSTRAINT FK_GroupsLectures_Lectures FOREIGN KEY ([LectureId]) REFERENCES [Lectures]([Id])
);
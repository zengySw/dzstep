# task 1
def task_1(*args):
    return sum(args)

print(task_1(1, 2, 3))


# task 2
def task_2(**kwargs):
    for key, value in kwargs.items():
        print(f"  {key}: {value}")

task_2(name="Олег", age=20, city="Одесса")


# task 3
def task_3(name, country='Ukraine'):
    print(f"Привет, {name}! Страна: {country}")

task_3("Олег")
task_3("John", country="USA")


# task 4
def task_4(name, age, city):
    return f"Имя: {name}, Возраст: {age}, Город: {city}"

print(task_4(name="Олег", age=20, city="Одесса"))


# task 5
def task_5(greeting):
    def say_hello(name):
        print(f"{greeting}, {name}!")
    return say_hello

hello = task_5("Привет")
hello("Олег")


# task 6
def task_6(n):
    if n == 0 or n == 1:
        return 1
    return n * task_6(n - 1)

print(task_6(5))


# task 7
def task_7(n):
    if n == 1:
        return 1
    return n + task_7(n - 1)

print(task_7(5))


# task 8
numbers = [1, 2, 3, 4, 5]
result = list(map(lambda n: n * 2, numbers))
print(result)


# task 9
task_9 = lambda x: x ** 2
print(task_9(5))


# task 10
pairs = [("banana", 3), ("apple", 1), ("cherry", 2)]
print(sorted(pairs, key=lambda x: x[1]))


# task 11
numbers = [1, 2, 3, 4, 5]
print(list(map(lambda x: x ** 2, numbers)))
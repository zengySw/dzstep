# 1. Змінні
name = "Олексій"
age = 20
city = "Київ"
is_student = True
print(f"{name}\n{age}\n{city}\n{is_student}")

# 2. Арифметика
a = int(input("Введіть перше число: "))
b = int(input("Введіть друге число: "))
print(f"Сума: {a + b}, Різниця: {a - b}, Добуток: {a * b}, Ділення: {a / b}")

# 3. Об'єм паралелепіпеда
l = float(input("Довжина: "))
w = float(input("Ширина: "))
h = float(input("Висота: "))
print(f"Об'єм: {l * w * h}")

# 4. Перетворення типів
s = input("Введіть число: ")
print(f"int: {int(s)}, float: {float(s)}")

# 5. Обмін значеннями без третьої змінної
x = 5
y = 10
x, y = y, x
print(f"x: {x}, y: {y}")
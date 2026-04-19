# 6. Повноліття
age = int(input("Ваш вік: "))
print("Повнолітній" if age >= 18 else "Неповнолітній")

# 7. Знак числа
num = float(input("Число: "))
if num > 0: print("Додатне")
elif num < 0: print("Від'ємне")
else: print("Нуль")

# 8. Парність
num = int(input("Ціле число: "))
print("Парне" if num % 2 == 0 else "Непарне")

# 9. Більше з двох
a, b = float(input("a: ")), float(input("b: "))
if a > b: print(a)
elif b > a: print(b)
else: print("Числа рівні")

# 10. Рівень оцінки
score = int(input("Бал (0-100): "))
if score >= 90: print("Високий")
elif score >= 70: print("Достатній")
elif score >= 50: print("Середній")
else: print("Низький")

# 11. Проміжок
num = float(input("Число: "))
print("Належить" if 10 <= num <= 50 else "Не належить")

# 12. Логін і пароль
login = input("Логін: ")
password = input("Пароль: ")
if login == "admin" and password == "1234":
    print("Успішний вхід")
else:
    print("Помилка доступу")
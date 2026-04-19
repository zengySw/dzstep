# 13. Числа 1-20
for i in range(1, 21):
    print(i, end=" ")
print()

# 14. Парні 2-30
for i in range(2, 31, 2):
    print(i, end=" ")
print()

# 15. Сума 1 до N
n = int(input("N: "))
print(f"Сума: {sum(range(1, n + 1))}")

# 16. Таблиця множення
num = int(input("Число: "))
for i in range(1, 11):
    print(f"{num} x {i} = {num * i}")

# 17. Факторіал
n = int(input("Натуральне число: "))
fact = 1
for i in range(1, n + 1):
    fact *= i
print(f"Факторіал: {fact}")

# 18. Кількість цифр
num = abs(int(input("Число: ")))
print(f"Кількість цифр: {len(str(num))}")
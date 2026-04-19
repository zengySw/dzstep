# 19. Список із 5 чисел
nums = [10, 20, 30, 40, 50]
print(f"Список: {nums}, Перший: {nums[0]}, Останній: {nums[-1]}, Сума: {sum(nums)}")

# 20. Пошук у списку
data = [1, 5, 8, 12, 45]
val = int(input("Введіть число: "))
print("Є у списку" if val in data else "Немає")

# 21. Фільтрація списку
lst = [2, 7, 1, 9, 4, 12, 3, 8, 0, 6]
print([x for x in lst if x > 5])

# 22. Довжина та символи рядка
s = input("Рядок: ")
print(f"Довжина: {len(s)}, Перший: {s[0]}, Останній: {s[-1]}")

# 23. Регістр
s = input("Рядок: ")
print(f"Верхній: {s.upper()}, Нижній: {s.lower()}")

# 24. Голосні літери
s = input("Рядок: ").lower()
vowels = "аеєиіїоуюяaeiouy"
count = sum(1 for char in s if char in vowels)
print(f"Голосних: {count}")
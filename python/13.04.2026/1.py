# task 1
def task_1(start=0):
    total = [start]
    def add(n):
        total[0] += n
        return total[0]
    return add

acc = task_1(10)
print(acc(5))   # 15
print(acc(3))   # 18
print(acc(-2))  # 16


# task 2
def task_2(prefix):
    def check(string):
        return string.startswith(prefix)
    return check

check_py = task_2("py")
print(check_py("python"))   # True
print(check_py("pyramid"))  # True
print(check_py("java"))     # False
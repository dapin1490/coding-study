sugar = 0
n = int(input())

while True:
    if n % 5 == 0 and n >= 0:
        break
    elif n < 0:
        sugar = -1
        n = 0
        break

    n -= 3
    sugar += 1

print(sugar + (n // 5))

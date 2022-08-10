v = [0] * 9
ar = [1] * 9
n = 0
idx = 0
for i in range(9):
    v[i] = int(input())
    n += v[i]

v = sorted(v)

for i in range(9):
    n -= v[i]
    ar[i] = 0
    for j in range(i + 1, 9):
        n -= v[j]
        if n == 100:
            ar[j] = 0
            break
        else:
            n += v[j]
    if n == 100:
        break
    n += v[i]
    ar[i] = 1

for i in range(9):
    if ar[i]:
        print(v[i])

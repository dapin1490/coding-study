ar = []
for i in range(0, 9):
    n = int(input())
    ar.append(n)

max = 0
index = -1

for i in range(0, 9):
    if ar[i] > max:
        max = ar[i]
        index = i + 1

print(max)
print(index)

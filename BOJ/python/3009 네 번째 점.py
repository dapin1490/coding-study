x = [0, 0, 0]
y = [0, 0, 0]
for i in range(3):
    x[i], y[i] = map(int, input().split())

if x[0] == x[1]:
    print(x[2], end=" ")
elif x[0] == x[2]:
    print(x[1], end=" ")
else:
    print(x[0], end=" ")

if y[0] == y[1]:
    print(y[2])
elif y[0] == y[2]:
    print(y[1])
else:
    print(y[0])

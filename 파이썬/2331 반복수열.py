lis = []
a, p = input().split()
p = int(p)
b = 0

lis.append(int(a))
while True:
    for i in a:
        b += int(i) ** p
    if lis.count(b) <= 0:
        lis.append(b)
        a = str(b)
        b = 0
    else:
        break

print(lis.index(b))

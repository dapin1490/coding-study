n = int(input())
ans = 0
for i in range(n):
    s = 0
    num = str(i)
    for j in num:
        s += int(j)
    s += i
    if s == n:
        ans = i
        break

print(ans)

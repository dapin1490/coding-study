idx = 0
maxi = 0

for i in range(1, 6):
    a, b, c, d = map(int, input().split())
    a = a + b + c + d
    if a > maxi:
        maxi = a
        idx = i

print("{} {}".format(idx, maxi))

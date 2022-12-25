def sosu(nn):
    if nn < 2:
        return False
    for ii in range(2, nn):
        if nn % ii == 0:
            return False
    return True


sum_sosu = 0
min_sosu = 10001
m = int(input())
n = int(input())

for i in range(m, n + 1):
    if sosu(i):
        sum_sosu += i
        if i < min_sosu:
            min_sosu = i

if sum_sosu == 0:
    print(-1)
else:
    print(sum_sosu)
    print(min_sosu)

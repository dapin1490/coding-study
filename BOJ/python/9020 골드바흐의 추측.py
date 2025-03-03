v = [True] * 10001
v[0] = False
v[1] = False
# 에라토스테네스의 체
for i in range(2, 5001):
    for j in range(i * 2, 10001, i):
        v[j] = False

t = int(input())
for tt in range(t):
    n = int(input())
    idx = n // 2
    id2 = n - idx
    while True:
        if v[idx] and v[id2]:
            break
        else:
            idx -= 1
            id2 += 1
    print(idx, id2)

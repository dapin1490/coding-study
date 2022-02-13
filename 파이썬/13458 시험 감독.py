def hire(p, bb, cc):
    if p > bb:
        cn = 1
        p -= bb
        cn += p // cc
        if p % cc != 0:
            cn += 1
        return cn
    else:
        return 1


t = int(input())  # 시험장 개수
lis = list(map(int, input().split()))  # 사람 수
b, c = map(int, input().split())
ans = 0

for i in lis:
    ans += hire(i, b, c)

print(ans)

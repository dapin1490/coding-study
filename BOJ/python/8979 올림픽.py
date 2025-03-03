# 8979 올림픽: https://www.acmicpc.net/problem/8979
# https://dapin1490.github.io/satinbower/posts/it-boj-8979/

n, k = map(int, input().split(' '))
lis = []
rank = 0
idx = 0

for i in range(n):
    country, gold, silver, bronze = map(int, input().split(' '))
    lis.append((gold, silver, bronze, country))

lis = sorted(lis, reverse=True)

for i in range(n):
    if lis[i][3] == k:
        idx = i
        rank = i + 1
        break

for i in range(idx - 1, -1, -1):
    if lis[i][:3] == lis[idx][:3]:
        rank -= 1
    else:
        break

print(rank)
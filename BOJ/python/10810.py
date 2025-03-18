n, m = map(int, input().split())
balls = [0] * (n + 1)

for _ in range(m):
    i, j, k = map(int, input().split())
    for x in range(i, j + 1):
        balls[x] = k

print(str(balls[1:]).replace('[', '').replace(']', '').replace(',', ''))
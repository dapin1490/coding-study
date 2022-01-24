import math

PI = 3.14
t = int(input())
for i in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = math.sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
    r = r1 + r2
    small = min(r1, r2)
    big = max(r1, r2)

    # 1. 큰 원 안에 작은 원이 있고 교점이 없음(0)
    # >> big > d + small
    # 2-1. 큰 원 안에 작은 원이 있고 교점이 1개 있음(1)
    # >> big == d + small
    # 2-2. 큰 원 안에 작은 원이 있고 교점이 2개 있음(2)
    # >> big < d + small
    # 2-3. 두 원이 완전히 겹침(-1)
    # >> r1 == r2 && d == 0
    # 3. 두 원이 2개의 점에서 만남(2)
    # >> d > big && d < r
    # 4. 두 원이 1개의 점에서 외접함(1)
    # >> d == r
    # 5. 두 원이 만나지 않음(0)
    # >> d > r

    if d == 0 and r1 == r2:
        print(-1)
    elif big > d + small or d > r:
        print(0)
    elif d == r or big == d + small:
        print(1)
    elif (big < d + small) or (d > big and d < r):
        print(2)

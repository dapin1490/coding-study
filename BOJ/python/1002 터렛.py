# https://www.acmicpc.net/problem/1002

"""
조규현, 백승환, 이석원, 류재명

조규현, 백승환: 터렛
이석원: 오퍼레이터
류재명: 적

각 터렛이 적과의 거리를 계산한다. 터렛의 좌표 및 계산된 거리를 보고 적이 있을 수 있는 위치의 수를 답하라.

비교 대상은 셋: d, r1, r2

동일한 두 원, 두 원이 겹치는 경우, 접하는 경우, 만나지 않는 경우 네 가지 경우로 구분

0. 두 원이 같다면 중심과 반지름이 모두 같다.
1. 겹친다면 두 원의 중심과 교점으로 삼각형을 만들 수 있다
2. 접한다면 두 원의 중심 사이에 접점이 있거나, 큰 원의 중심과 접점 사이에 작은 원의 중심이 있다.
3. 그 외에는 모두 만나지 않는 경우이다.
"""
import math

def find_enemy() -> int:
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    lis = sorted([d, r1, r2])  # min, mid, max

    if (x1, y1) == (x2, y2) and r1 == r2:  # 서로 같은 원
        return -1
    if lis[2] < lis[1] + lis[0]:  # 두 반지름과 중심 거리로 삼각형 성립
        return 2
    if math.isclose(lis[2], lis[1] + lis[0]) or math.isclose(r1 + r2, d):  # 내접, 외접
        return 1
    return 0  # 그 외

n = int(input())

for _ in range(n):
    print(find_enemy())

"""
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
"""
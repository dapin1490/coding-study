# 동적 계획법

global me
me = [[[0] * 102 for _ in range(102)] for __ in range(102)]


def w(a, b, c):
    global me

    if me[50 + a][50 + b][50 + c] != 0:
        return me[50 + a][50 + b][50 + c]

    if a <= 0 or b <= 0 or c <= 0:
        ans = 1
        me[50 + a][50 + b][50 + c] = ans
        return ans
    elif a > 20 or b > 20 or c > 20:
        ans = w(20, 20, 20)
        me[50 + a][50 + b][50 + c] = ans
        return ans
    elif a < b < c:
        ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
        me[50 + a][50 + b][50 + c] = ans
        return ans
    else:
        ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
        me[50 + a][50 + b][50 + c] = ans
        return ans


while True:
    x, y, z = map(int, input().split())
    if x == -1 and y == -1 and z == -1:
        break
    print("w({}, {}, {}) = {}".format(x, y, z, w(x, y, z)))

def q1(a1, b1):
    global v
    a1 -= 1
    b1 -= 1
    ans1 = 0
    for i in range(a1, b1 + 1):
        ans1 += v[i]
    v[a1], v[b1] = v[b1], v[a1]
    return ans1


def q2(a2, b2, c2, d2):
    global v
    a2 -= 1
    b2 -= 1
    c2 -= 1
    d2 -= 1
    ans2 = 0
    if a2 <= c2 <= b2 <= d2:
        for i in range(a2, c2):
            ans2 += v[i]
        for j in range(b2 + 1, d2 + 1):
            ans2 -= v[j]
    else:
        for i in range(a2, b2 + 1):
            ans2 += v[i]
        for j in range(c2, d2 + 1):
            ans2 -= v[j]
    return ans2


global v
n, q = map(int, input().split())
v = list(map(int, input().split()))
qa = []
for k in range(q):
    qa = list(map(int, input().split()))
    if qa[0] == 1:
        print(q1(qa[1], qa[2]))
    else:
        print(q2(qa[1], qa[2], qa[3], qa[4]))

nvi = [0, 0, 0, 0, 0, 0, 0, 0]
v = []
global idn
idn = 0


def pr(n, m):
    global idn
    if len(v) == m:
        for k in v:
            print(k, end=" ")
        print()
        return

    for i in range(n):
        if nvi[i] >= m or (i + 1) < idn:
            continue
        v.append(i + 1)
        idn = i + 1
        nvi[i] += 1
        pr(n, m)
        idx = len(v)
        del v[idx - 1]
        idn = 0
        nvi[i] -= 1


if __name__ == '__main__':
    nn, mm = map(int, input().split())
    pr(nn, mm)

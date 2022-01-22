nvi = [0, 0, 0, 0, 0, 0, 0, 0]
v = []


def pr(n, m):
    if len(v) == m:
        for k in v:
            print(k, end=" ")
        print()
        return

    for i in range(n):
        if nvi[i]:
            continue
        v.append(i + 1)
        nvi[i] = 1
        pr(n, m)
        idx = len(v)
        del v[idx - 1]
        nvi[i] = 0


if __name__ == '__main__':
    nn, mm = map(int, input().split())
    pr(nn, mm)

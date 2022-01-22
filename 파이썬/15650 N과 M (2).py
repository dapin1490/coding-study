nvi = [0, 0, 0, 0, 0, 0, 0, 0]
v = []
global pre_num
pre_num = 0


def pr(n, m):
    global pre_num
    if len(v) == m:
        for k in v:
            print(k, end=" ")
        print()
        return

    for i in range(n):
        if nvi[i] or (i + 1) < pre_num:
            continue
        v.append(i + 1)
        pre_num = i + 1
        nvi[i] = 1
        pr(n, m)
        idx = len(v)
        del v[idx - 1]
        pre_num = 0
        nvi[i] = 0


if __name__ == '__main__':
    nn, mm = map(int, input().split())
    pr(nn, mm)

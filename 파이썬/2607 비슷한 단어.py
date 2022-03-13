t = int(input())
cnt = 0
key = list(input())
key_len = len(key)

for _ in range(1, t):
    value = list(input())
    nw = 0

    for i in range(key_len):
        itm = value.count(key[i])
        if itm > 0:
            value.remove(key[i])
        else:
            nw += 1

    if nw <= 1 and len(value) <= 1:
        cnt += 1

print(cnt)

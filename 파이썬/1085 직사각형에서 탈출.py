x, y, w, h = map(int, input().split())
d = [0, 0, 0, 0]
d[0] = w - x  # 동
d[1] = w - d[0]  # 서
d[2] = h - y  # 북
d[3] = h - d[2]  # 남

min_dis = 1000
for dist in d:
    if dist < min_dis:
        min_dis = dist

print(min_dis)

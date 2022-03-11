a, b = map(int, input().split())
maxi = 0
for i in range(1, b + 1):
    num = a * i
    str_num = str(num)
    re_num = ""
    for j in range(len(str_num) - 1, -1, -1):
        re_num += str_num[j]

    if int(re_num) > maxi:
        maxi = int(re_num)

print(maxi)

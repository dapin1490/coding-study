def fly(start, end):
    len = end - start
    count = 0
    distance = 1
    while True:
        if len == 0:
            break
        if len >= distance * 2:
            len -= distance * 2
            count += 2
            distance += 1
        elif len >= (distance * 2 - 1) and distance != 1:
            len -= (distance * 2 - 1)
            count += 2
        elif len == distance:
            len -= distance
            count += 1
        else:
            distance -= 1
    return count


t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    print(fly(a, b))

def eu(big, small):
    if big < small:
        big, small = small, big

    last = 1
    while True:
        if big % small == 0:
            break
        last = big % small
        big = small
        small = last

    return small


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(a * b // eu(a, b))

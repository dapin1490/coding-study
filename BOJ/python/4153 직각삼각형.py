while True:
    tri = list(map(int, input().split()))
    if tri[0] == 0:
        break
    tri = sorted(tri, reverse=True)

    if pow(tri[0], 2) == (pow(tri[1], 2) + pow(tri[2], 2)):
        print("right")
    else:
        print("wrong")

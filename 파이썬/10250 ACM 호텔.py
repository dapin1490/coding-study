def find_room(h, w, n):
    line = 1
    address = h

    while n > address:
        address += h
        line += 1

    if line > w:
        return "There is no room."

    xx = line
    yy = h - (address - n)
    room = ""

    if xx < 10:
        room = str(yy) + "0" + str(xx)
    else:
        room = str(yy) + str(xx)

    return room


t = int(input())
for i in range(t):
    hh, ww, nn = map(int, input().split())
    print(find_room(hh, ww, nn))

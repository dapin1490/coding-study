a, b = map(int, input().split())

ra = int(a / 100) + (int((a % 100) / 10) * 10) + ((a % 10) * 100)
rb = int(b / 100) + (int((b % 100) / 10) * 10) + ((b % 10) * 100)

if ra > rb:
    print(ra)
else:
    print(rb)

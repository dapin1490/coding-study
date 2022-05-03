import sys

is_valid = lambda a, b: (abs(ord(a[0]) - ord(b[0])) == 2 and abs(int(a[1]) - int(b[1])) == 1) or (abs(ord(a[0]) - ord(b[0])) == 1 and abs(int(a[1]) - int(b[1])) == 2)

flag = True
plate = [[0] * 6 for _ in range(6)]
now_seat = sys.stdin.readline().strip()
start_seat = now_seat
plate[ord(now_seat[0]) - ord("A")][int(now_seat[1]) - 1] = 1

for _ in range(1, 36):
    next_seat = sys.stdin.readline().strip()
    if not is_valid(now_seat, next_seat) or plate[ord(next_seat[0]) - ord("A")][int(next_seat[1]) - 1] != 0:
        flag = False
        break
    now_seat = next_seat
    plate[ord(now_seat[0]) - ord("A")][int(now_seat[1]) - 1] = 1

if flag and is_valid(start_seat, now_seat):
    print("Valid")
else:
    print("Invalid")

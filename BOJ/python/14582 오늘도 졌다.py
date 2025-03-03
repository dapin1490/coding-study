ol = list(map(int, input().split()))
st = list(map(int, input().split()))
flag = False

for i in range(1, 9):
	ol[i] += ol[i - 1]
	st[i] += st[i - 1]

ol = ol + [ol[8]]
st = [0] + st

for i in range(9):
	if ol[i] > st[i]:
		flag = True
		break

print("Yes" if flag else "No")

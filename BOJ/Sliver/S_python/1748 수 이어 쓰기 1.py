n = input()
ans = 0
i = len(n)
n = int(n)

if i >= 9:
	ans += 9
if i >= 8:
	ans += 90000000 * 8 if n >= 100000000 else (n - 9999999) * 8
if i >= 7:
	ans += 9000000 * 7 if n >= 10000000 else (n - 999999) * 7
if i >= 6:
	ans += 900000 * 6 if n >= 1000000 else (n - 99999) * 6
if i >= 5:
	ans += 90000 * 5 if n >= 100000 else (n - 9999) * 5
if i >= 4:
	ans += 9000 * 4 if n >= 10000 else (n - 999) * 4
if i >= 3:
	ans += 900 * 3 if n >= 1000 else (n - 99) * 3
if i >= 2:
	ans += 90 * 2 if n >= 100 else (n - 9) * 2
if i >= 1:
	ans += 9 if n >= 10 else n

print(ans)

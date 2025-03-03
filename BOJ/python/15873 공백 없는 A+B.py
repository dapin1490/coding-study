ab = input()
if len(ab) == 2:
	print(int(ab[0]) + int(ab[1]))
elif len(ab) == 4:
	print(20)
else:
	idx = ab.find("0")
	if idx == 1:
		print(int(ab[0:2]) + int(ab[2:]))
	else:
		print(int(ab[0]) + int(ab[1:]))

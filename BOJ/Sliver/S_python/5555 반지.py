key = input()
n = int(input())
cnt = 0

for _ in range(n):
	value = input()
	value *= 2
	idx = value.find(key)
	cnt += 1 if idx >= 0 else 0

print(cnt)

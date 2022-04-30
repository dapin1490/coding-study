ans = int(input())
tests = list(map(int, input().split()))
cnt = 0

for i in tests:
	cnt += 1 if i == ans else 0

print(cnt)

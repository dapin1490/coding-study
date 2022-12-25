import sys

key = sys.stdin.readline().strip()
n = int(sys.stdin.readline())
dic = [sys.stdin.readline().strip() for _ in range(n)]
flag = False

for i in range(26):
	value = ""
	for j in range(len(key)):
		value += chr((ord(key[j]) - ord('a') + i) % 26 + ord('a'))
	for word in dic:
		if value.find(word) >= 0:
			flag = True
			break
	if flag:
		print(value)
		break

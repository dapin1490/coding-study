s = input()

ar = []
for i in range(26):
    ar.append(0)

for i in range(len(s)):
    if ord(s[i]) >= ord('a'):
        n = ord(s[i]) - ord('a')
    else:
        n = ord(s[i]) - ord('A')

    ar[n] = ar[n] + 1

max_num = 0
max_index = 0
same = False

for i in range(26):
    if ar[i] > max_num:
        max_num = ar[i]
        max_index = i

for i in range(max_index + 1, 26):
    if ar[i] == max_num:
        same = True
        break

if same:
    print("?")
else:
    print(chr(max_index + ord('A')))

s = input()

word = False
count = 0

for i in range(len(s)):
    if s[i] != ' ':
        word = True

    if s[i] == ' ' and word:
        count += 1
        word = False

    if i == len(s) - 1 and word:
        count += 1

print(count)

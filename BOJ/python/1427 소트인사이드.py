s = input()
a = []
for i in range(len(s)):
    a.append(s[i])

a = sorted(a, reverse=True)
for n in a:
    print(n, end='')

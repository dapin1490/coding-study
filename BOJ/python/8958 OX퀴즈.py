def score(s):
    size = len(s)
    total = 0
    count = 0
    for i in range(size):
        if s[i] == 'O':
            count += 1
            total += count
        elif s[i] == 'X':
            count = 0
    return total


n = int(input())

for ii in range(n):
    t = input()
    print(score(t))
